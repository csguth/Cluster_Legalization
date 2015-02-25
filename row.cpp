#include "row.h"
namespace Overlap_Removal {

Row::Row(int begin, int end) :_begin(begin), _end(end)
{
    if(_end < _begin)
        throw Invalid_Range();
    clear();
}

Row::Row(const Overlap_Removal::Row &other): _begin(other._begin), _end(other._end)
{
    for(std::list<Overlap_Removal::Cluster>::const_iterator it = other._clusters.begin(); it != other._clusters.end(); it++)
    {
        Cluster_Iterator inserted = _clusters.insert(_clusters.end(), (*it));
        inserted->set_cluster_iterator_to_all_ranges(inserted);
    }
}

void Row::clear()
{
    _clusters.clear();
    _clusters.push_back(Cluster(_begin, _end));
}

int Row::begin()
{
    return _begin;
}

int Row::end()
{
    return _end;
}

int Row::number_of_clusters()
{
    return _clusters.size();
}

const Cluster &Row::cluster(int index)
{
    Cluster_Iterator it = _clusters.begin();
    std::advance(it, index);
    return *it;
}

Cluster_Iterator Row::insert_range_in_cluster(Cluster_Iterator cluster, std::pair<int, int> range, int id)
{
    if(!cluster->is_free_space())
        throw Already_Filled();
    else if(!cluster->has_capacity(range.second-range.first+1) || cluster->end()-range.first < range.second-range.first)
        throw Range_Too_Big();
    if(cluster->begin() == range.first && cluster->end() == range.second) // CASO1: Célula ocupa o cluster inteiro
        cluster = __fill_cluster_with_a_range(cluster, range.first, range.second, id);
    else if(cluster->begin() == range.first && range.second < cluster->end()) // CASO2: Célula ocupa o início do cluster
        cluster = __place_range_at_beginning_of_cluster(cluster, range.first, range.second, id);
    else if(cluster->end() == range.second && range.first > cluster->begin()) // CASO3: Célula ocupa o fim do cluster
        cluster = __place_range_at_end_of_cluster(cluster, range.first, range.second, id);
    else if(range.first > cluster->begin() && range.second < cluster->end()) // CASO4: Célula ocupa o meio do cluster
        cluster = __place_range_at_middle_of_cluster(cluster, range.first, range.second, id);
    return cluster;
}

Cluster_Iterator Row::__fill_cluster_with_a_range(Cluster_Iterator cluster, int begin, int end, int id)
{
    Cluster * c = &(*cluster);
    Range_In_Cluster range(id, 0, end - c->begin());
    range.cluster(cluster);
    c->add_at_end(range);
    cluster = __clusterize_with_previous(cluster);
    cluster = __clusterize_with_next(cluster);
    return cluster;
}

Cluster_Iterator Row::__place_range_at_beginning_of_cluster(Cluster_Iterator cluster, int begin, int end, int id)
{
    Cluster * c = &(*cluster);
    int end_before = c->end();
    c->end(end);

    Range_In_Cluster range(id, 0, end - c->begin());
    range.cluster(cluster);
    c->add_at_end(range);

    cluster = __clusterize_with_previous(cluster);
    Cluster_Iterator next(cluster);
    next++;
    _clusters.insert(next, Cluster(end+1, end_before));
    return cluster;
}

Cluster_Iterator Row::__place_range_at_end_of_cluster(Cluster_Iterator cluster, int begin, int end, int id)
{
    Cluster * c = &(*cluster);
    int begin_before = c->begin();
    c->begin(begin);
    Range_In_Cluster range(id, 0, end - c->begin());
    range.cluster(cluster);
    c->add_at_end(range);
    cluster = __clusterize_with_next(cluster);
    _clusters.insert(cluster, Cluster(begin_before, begin-1));
    return cluster;
}

Cluster_Iterator Row::__place_range_at_middle_of_cluster(Cluster_Iterator cluster, int begin, int end, int id)
{
    Cluster * c = &(*cluster);
    int begin_before = c->begin();
    int end_before = c->end();
    Cluster_Iterator next(cluster);
    next++;
    _clusters.insert(cluster, Cluster(begin_before, begin-1));
    _clusters.insert(next, Cluster(end+1, end_before));
    c->begin(begin);
    c->end(end);
    Range_In_Cluster range(id, begin, end);
    range.cluster(cluster);
    c->add_at_end(range);
    return cluster;
}

Cluster_Iterator Row::__find_cluster_by_range(int begin, int end)
{
    if(end < begin)
        throw Invalid_Range();
    if(begin < _begin || end > _end)
        throw Out_of_Bounds();
    return std::find_if(_clusters.begin(), _clusters.end(), Cluster_Has_Range(begin, begin));
}

Cluster_Iterator Row::insert_range(int begin, int end, int id)
{
    if(begin < _begin || end > _end)
        throw Out_of_Bounds();
    if(end < begin)
        throw Invalid_Range();
    Cluster_Iterator cluster = __find_cluster_by_range(begin, end);
    return insert_range_in_cluster(cluster, std::make_pair(begin, end), id);
}

Cluster_Iterator Row::insert_range(std::pair<int, int> range, int id)
{
    return insert_range(range.first, range.second, id);
}

void Row::__remove_free_cluster(Cluster_Iterator cluster)
{
    Cluster_Iterator next(cluster);
    next++;
    _clusters.erase(cluster);
    if(next != _clusters.end())
        cluster =__clusterize_with_previous(next);
    else
    {
        if(_clusters.empty())
            clear();
        else
        {
            next--;
            next->end(_end);
        }
    }
}

void Row::remove_by_id(int id)
{
    Cluster_Iterator cluster =  std::find_if(_clusters.begin(), _clusters.end(), Cluster_Has_Id(id));
    std::list<Cluster> new_clusters = cluster->split(id);
    if(new_clusters.empty())
        return __remove_free_cluster(cluster);

    if(cluster != _clusters.begin())
    {
        Cluster_Iterator previous(cluster);
        previous--;
        if(previous->is_free_space())
            previous->end(new_clusters.front().begin()-1);
    }
    else if(new_clusters.front().begin() != _begin)
        _clusters.insert(cluster, Cluster(_begin, new_clusters.front().begin()-1));

    Cluster_Iterator next(cluster);
    next++;
    if(next != _clusters.end())
    {
        if(next->is_free_space())
            next->begin(new_clusters.back().end()+1);
    }
    else if(new_clusters.back().end() != _end)
        _clusters.insert(next, Cluster(new_clusters.back().end()+1, _end));
    _clusters.insert(cluster, new_clusters.begin(), new_clusters.end());
    Cluster_Iterator previous(cluster);
    while(previous != _clusters.begin())
    {
        previous--;
        for(std::list<Range_In_Cluster>::iterator it = previous->ranges().begin(); it != previous->ranges().end(); it++)
            it->cluster(previous);
    }
    _clusters.erase(cluster);
}

std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > Row::get_previous_and_next_free(std::pair<int, int> range, double ratio)
{
    return get_previous_and_next_free(range.first, range.second, ratio);
}

Cluster_Iterator Row::__find_first_cluster_on_the_right(Cluster_Iterator cluster, int size)
{
    Cluster_Iterator next(cluster);
    next++;
    Cluster_Iterator right = _clusters.end();
    if(next != _clusters.end())
    {
        while(!next->has_capacity(size) && next != _clusters.end())
            next++;
        if(next->has_capacity(size) && next != _clusters.end())
            right = next;
    }
    return right;
}

Cluster_Iterator Row::__find_first_cluster_on_the_left(Cluster_Iterator cluster, int size)
{
    Cluster_Iterator left = _clusters.end();
    if(cluster != _clusters.begin())
    {
        Cluster_Iterator previous(cluster);
        previous--;
        while(!previous->has_capacity(size) && previous != _clusters.begin())
            previous--;
        if(previous->has_capacity(size))
            left = previous;
    }
    return left;
}

std::pair<std::pair<Cluster_Iterator, int> , std::pair<Cluster_Iterator, int> > Row::get_previous_and_next_free(int begin, int end, double ratio)
{
    Cluster_Iterator cluster = find_cluster_by_value(begin);
    int size = end-begin+1;

    if(cluster != _clusters.end())
    {
        if(cluster->is_free_space())
        {
            std::pair<int, int> intersect(std::max(begin, cluster->begin()), std::min(end, cluster->end()));
            int intersect_size = intersect.second-intersect.first+1;

            if(static_cast<double>(intersect_size)/static_cast<double>(size) >= ratio)
            {
                if(intersect_size == size)
                    return std::make_pair(std::make_pair(cluster, begin), std::make_pair(cluster, begin));
                Cluster_Iterator next(cluster);
                next++;
                if(next != _clusters.end())
                {
                    if(free_space_on_right(next) >= size - intersect_size)
                        return std::make_pair(std::make_pair(cluster, begin), std::make_pair(cluster, begin));
                }
            }
            cluster++;
        } else
        {
            std::pair<int, int> intersect(std::max(begin, cluster->begin()), std::min(end, cluster->end()));
            int intersect_size = intersect.second-intersect.first+1;
            if(static_cast<double>(intersect_size)/static_cast<double>(size) < (1-ratio))
            {
                if(free_space_on_left(cluster) >= intersect_size)
                {
                    Cluster_Iterator next(cluster);
                    next++;
                    if(next != _clusters.end())
                    {
                        if(next->end() >= end)
                            return std::make_pair(std::make_pair(cluster, begin), std::make_pair(cluster, begin));
                        next++;
                        if(next != _clusters.end())
                        {
                            if(next->begin() > end || free_space_on_right(next) >= size-intersect_size)
                                return std::make_pair(std::make_pair(cluster, begin), std::make_pair(cluster, begin));
                        }
                    }
                }
            }
        }
    }
    Cluster_Iterator left = __find_first_cluster_on_the_left(cluster, size);
    Cluster_Iterator right = __find_first_cluster_on_the_right(cluster, size);
    std::pair<Cluster_Iterator, int> left_pair(left, (left != _clusters.end() ? left->end() - size + 1 : -1));
    std::pair<Cluster_Iterator, int> right_pair(right, (right != _clusters.end() ? right->begin() : -1));
    return std::make_pair(left_pair, right_pair);
}

Cluster_Iterator Row::__clusterize_with_next(Cluster_Iterator cluster_it)
{
    Cluster_Iterator next(cluster_it);
    next++;
    if(next == _clusters.end())
        return cluster_it;
    if(!next->is_free_space() && !cluster_it->is_free_space())
    {
        for(std::list<Range_In_Cluster>::iterator it = next->ranges().begin(); it != next->ranges().end(); it++)
            it->cluster(cluster_it);
        cluster_it->add_at_end(next->ranges());
        _clusters.erase(next);
        return cluster_it;
    }
    return cluster_it;
}

Cluster_Iterator Row::__clusterize_with_previous(Cluster_Iterator cluster_it)
{
    if(cluster_it == _clusters.begin())
    {
        cluster_it->begin(_begin);
        return cluster_it;
    }
    Cluster_Iterator previous(cluster_it);
    previous--;
    if(!previous->is_free_space() && !cluster_it->is_free_space())
    {
        for(std::list<Range_In_Cluster>::iterator it = cluster_it->ranges().begin(); it != cluster_it->ranges().end(); it++)
            it->cluster(previous);
        previous->add_at_end(cluster_it->ranges());
        _clusters.erase(cluster_it);
        return previous;
    }
    else if(previous->is_free_space() && cluster_it->is_free_space())
    {
        previous->end(cluster_it->end());
        _clusters.erase(cluster_it);
        return previous;
    }
    return cluster_it;
}

Cluster_Iterator Row::move_cluster_to_right(Cluster_Iterator cluster_it, int step)
{
    if(cluster_it->is_free_space())
        throw Forbidden_Operation();
    if(step < 1)
        throw Invalid_Step_Size();
    // Checa se tem espaço
    Cluster_Iterator next(cluster_it);
    next++;
    if(next == _clusters.end())
        throw Not_Enough_Space();
    else if(!next->has_capacity(step))
        throw Not_Enough_Space();

    // Libera espaço na esquerda
    if(cluster_it == _clusters.begin())
        _clusters.insert(cluster_it, Cluster(_begin, _begin+step));

    Cluster_Iterator previous(cluster_it);
    previous--;
    previous->end(cluster_it->begin()-1+step);

    // Muda os limites do cluster
    cluster_it->begin(cluster_it->begin()+step);
    cluster_it->end(cluster_it->end()+step);

    // Diminui o cluster livre à direita e se precisar, remove-o
    next->begin(next->begin()+step);
    if(next->end() < next->begin())
        _clusters.erase(next);
    return __clusterize_with_next(cluster_it);
}

Cluster_Iterator Row::move_cluster_to_left(Cluster_Iterator cluster_it, int step)
{
    if(cluster_it->is_free_space())
        throw Forbidden_Operation();
    if(step < 1)
        throw Invalid_Step_Size();
    // Checa se tem espaço
    if(cluster_it == _clusters.begin())
        throw Not_Enough_Space();
    else {
        Cluster_Iterator previous(cluster_it);
        previous--;
        if(!previous->has_capacity(step))
            throw Not_Enough_Space();
    }

    // Libera espaço na direita
    Cluster_Iterator next(cluster_it);
    next++;

    if(next == _clusters.end())
        _clusters.push_back(Cluster(cluster_it->end() + 1 - step, _end));

    next->begin(next->begin()-step);

    // Muda os limites do cluster
    cluster_it->begin(cluster_it->begin()-step);
    cluster_it->end(cluster_it->end()-step);

    // Diminui o cluster livre à esquerda e se precisar, remove-o
    Cluster_Iterator previous(cluster_it);
    previous--;
    previous->end(previous->end()-step);
    if(previous->end() < previous->begin())
        _clusters.erase(previous);
    return __clusterize_with_previous(cluster_it);
}

Cluster_Iterator Row::find_cluster_by_range(std::pair<int, int> range)
{
    return __find_cluster_by_range(range.first, range.second);
}

Cluster_Iterator Row::find_cluster_by_value(int value)
{
    if(value < _begin || value > _end)
        throw Out_of_Bounds();
    return std::find_if(_clusters.begin(), _clusters.end(), Cluster_Has_Range(value, value));
}

Cluster_Iterator Row::first_cluster_iterator()
{
    return _clusters.begin();
}

Cluster_Iterator Row::not_valid_iterator()
{
    return _clusters.end();
}

int Row::free_space_on_right(Cluster_Iterator cluster)
{
    cluster++;
    if(cluster == _clusters.end())
        return 0;
    if(cluster->is_free_space())
        return cluster->end()-cluster->begin()+1;
    return 0;
}

int Row::free_space_on_left(Cluster_Iterator cluster)
{
    if(cluster == _clusters.begin())
        return 0;
    cluster--;
    if(cluster->is_free_space())
        return cluster->end()-cluster->begin()+1;
    return 0;
}

int Row::total_free_space_on_right(Cluster_Iterator cluster, int value)
{
    int space  = 0;
    if(cluster->is_free_space())
    {
        space = value-cluster->begin();
        cluster++;
    }
    if(cluster != _clusters.end())
    {
        cluster++;
        while(cluster != _clusters.end())
        {
            if(cluster->is_free_space())
                space += cluster->end()-cluster->begin()+1;
            cluster++;
        }
    }
    return space;
}

int Row::total_free_space_on_left(Cluster_Iterator cluster, int value)
{
    int space  = 0;
    if(cluster->is_free_space())
    {
        space = value-cluster->begin();
        if(cluster != _clusters.begin())
            cluster--;
    }
    if(!cluster->is_free_space())
    {
        while(cluster != _clusters.begin())
        {
            cluster--;
            if(cluster->is_free_space())
                space += cluster->end()-cluster->begin()+1;
        }
    }
    return space;
}

int Row::first_range_at_left_of(std::pair<int, int> range)
{
    int width = range.second-range.first+1;
    int middle = range.first+width/2;
    Cluster_Iterator the_cluster = find_cluster_by_value(middle);
    int id = -1;

    if(the_cluster->is_free_space() && the_cluster == _clusters.begin()) // there is no range at left
        return id;

    else if(the_cluster->is_free_space()) // there are ranges at left
        the_cluster--;

    for(std::list<Range_In_Cluster>::const_iterator the_range = the_cluster->ranges().begin(); the_range != the_cluster->ranges().end(); the_range++)
    {
        int range_width = the_range->end()-the_range->begin()+1;
        int range_middle = the_range->begin() + range_width/2;
        if(range_middle < middle)
            id = the_range->id();
        else break;
    }

    if(id == -1)
    {
        the_cluster--;
        if(the_cluster == _clusters.begin()) // free at begin
            return id;
        the_cluster--;
        for(std::list<Range_In_Cluster>::const_iterator the_range = the_cluster->ranges().begin(); the_range != the_cluster->ranges().end(); the_range++)
        {
            int range_width = the_range->end()-the_range->begin()+1;
            int range_middle = the_range->begin() + range_width/2;
            if(range_middle < middle)
                id = the_range->id();
            else break;
        }
    }
    return id;

}

int Row::first_range_at_right_of(std::pair<int, int> range)
{
    int width = range.second-range.first+1;
    int middle = range.first+width/2;
    Cluster_Iterator the_cluster = find_cluster_by_value(middle);

    if(the_cluster->is_free_space())
        the_cluster++;
    if(the_cluster == _clusters.end())
        return -1;
    int id = -1;
    for(std::list<Range_In_Cluster>::const_reverse_iterator the_range = the_cluster->ranges().rbegin(); the_range != the_cluster->ranges().rend(); the_range++)
    {
        int range_width = the_range->end()-the_range->begin()+1;
        int range_middle = the_range->begin() + range_width/2;
        if(range_middle > middle)
            id = the_range->id();
        else break;
    }
    if(id == -1)
    {
        the_cluster++;
        if(the_cluster != _clusters.end())
        {
            the_cluster++;
            if(the_cluster != _clusters.end())
            {
                for(std::list<Range_In_Cluster>::const_reverse_iterator the_range = the_cluster->ranges().rbegin(); the_range != the_cluster->ranges().rend(); the_range++)
                {
                    int range_width = the_range->end()-the_range->begin()+1;
                    int range_middle = the_range->begin() + range_width/2;
                    if(range_middle > middle)
                        id = the_range->id();
                    else break;
                }
            }
        }
    }

    return id;
}

Cluster_Iterator Row::find_cluster_by_id(int id)
{
    return std::find_if(_clusters.begin(), _clusters.end(), Cluster_Has_Id(id));
}

int Row::free_space()
{
    int space = 0;
    for(Cluster_Iterator the_cluster = _clusters.begin(); the_cluster != _clusters.end(); the_cluster++)
    {
        if(the_cluster->is_free_space())
            space += the_cluster->end()-the_cluster->begin()+1;
    }
    return space;
}

Cluster_Iterator Row::split_cluster_and_move_to_left(Cluster_Iterator cluster, int range_id, int step)
{
    // if the first range is the split point, just move
    if(cluster->ranges().back().id() == range_id)
        return move_cluster_to_left(cluster, step);

    // save the ranges
    std::list<std::pair<std::pair<int, int>, int> > ranges;
    for(std::list<Range_In_Cluster>::const_iterator the_range = cluster->ranges().begin(); the_range != cluster->ranges().end(); the_range++)
        ranges.push_back(std::make_pair(std::make_pair(the_range->begin(), the_range->end()), the_range->id()));

    // remove all ranges and move some of those to the left
    bool before = true;
    for(std::list<std::pair<std::pair<int, int>, int> >::iterator the_range = ranges.begin(); the_range != ranges.end(); the_range++)
    {
        remove_by_id(the_range->second);
        if(before)
        {
            the_range->first.first -= step;
            the_range->first.second -= step;
        }
        if(the_range->second == range_id)
            before = false;
    }

    // re-insert all ranges
    for(std::list<std::pair<std::pair<int, int>, int> >::iterator the_range = ranges.begin(); the_range != ranges.end(); the_range++)
        insert_range(the_range->first, the_range->second);
    return find_cluster_by_id(range_id);
}

Cluster_Iterator Row::split_cluster_and_move_to_right(Cluster_Iterator cluster, int range_id, int step)
{
    // if the first range is the split point, just move
    if(cluster->ranges().front().id() == range_id)
        return move_cluster_to_right(cluster, step);

    // save the ranges
    std::list<std::pair<std::pair<int, int>, int> > ranges;
    for(std::list<Range_In_Cluster>::const_iterator the_range = cluster->ranges().begin(); the_range != cluster->ranges().end(); the_range++)
        ranges.push_back(std::make_pair(std::make_pair(the_range->begin(), the_range->end()), the_range->id()));

    // remove all ranges and move some of those to the right
    bool after = true;
    for(std::list<std::pair<std::pair<int, int>, int> >::reverse_iterator the_range = ranges.rbegin(); the_range != ranges.rend(); the_range++)
    {
        remove_by_id(the_range->second);
        if(after)
        {
            the_range->first.first += step;
            the_range->first.second += step;
        }
        if(the_range->second == range_id)
            after = false;
    }

    // re-insert all ranges
    for(std::list<std::pair<std::pair<int, int>, int> >::iterator the_range = ranges.begin(); the_range != ranges.end(); the_range++)
        insert_range(the_range->first, the_range->second);
    return find_cluster_by_id(range_id);
}
}
