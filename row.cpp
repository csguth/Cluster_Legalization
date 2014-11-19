#include "row.h"
namespace Overlap_Removal {

Row::Row(int begin, int end) :_begin(begin), _end(end)
{
    if(_end < _begin)
        throw Invalid_Range();
    clear();
}

Row::Row(Row &other): _begin(other._begin), _end(other._end)
{
    for(std::list<Cluster>::iterator it = other._clusters.begin(); it != other._clusters.end(); it++)
    {
        std::list<Cluster>::iterator inserted = _clusters.insert(_clusters.end(), (*it));
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
    std::list<Cluster>::iterator it = _clusters.begin();
    std::advance(it, index);
    return *it;
}

std::list<Cluster>::iterator Row::__fill_cluster_with_a_range(std::list<Cluster>::iterator cluster, int begin, int end, int id)
{
    Cluster * c = &(*cluster);
    Range_In_Cluster range(id, 0, end - c->begin());
    range.cluster(cluster);
    c->add_at_end(range);
    cluster = __clusterize_with_previous(cluster);
    cluster = __clusterize_with_next(cluster);
    return cluster;
}

std::list<Cluster>::iterator Row::__place_range_at_beginning_of_cluster(std::list<Cluster>::iterator cluster, int begin, int end, int id)
{
    Cluster * c = &(*cluster);
    int end_before = c->end();
    c->end(end);

    Range_In_Cluster range(id, 0, end - c->begin());
    range.cluster(cluster);
    c->add_at_end(range);

    cluster = __clusterize_with_previous(cluster);
    std::list<Cluster>::iterator next(cluster);
    next++;
    _clusters.insert(next, Cluster(end+1, end_before));
    return cluster;
}

std::list<Cluster>::iterator Row::__place_range_at_end_of_cluster(std::list<Cluster>::iterator cluster, int begin, int end, int id)
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

std::list<Cluster>::iterator Row::__place_range_at_middle_of_cluster(std::list<Cluster>::iterator cluster, int begin, int end, int id)
{
    Cluster * c = &(*cluster);
    int begin_before = c->begin();
    int end_before = c->end();
    std::list<Cluster>::iterator next(cluster);
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

std::list<Cluster>::iterator Row::__find_cluster_by_range(int begin, int end)
{
    if(end < begin)
        throw Invalid_Range();
    if(begin < _begin || end > _end)
        throw Out_of_Bounds();
    return std::find_if(_clusters.begin(), _clusters.end(), Cluster_Has_Range(begin, begin));
}

std::list<Cluster>::iterator Row::insert_range(int begin, int end, int id)
{
    if(begin < _begin || end > _end)
        throw Out_of_Bounds();
    if(end < begin)
        throw Invalid_Range();
    std::list<Cluster>::iterator cluster = __find_cluster_by_range(begin, end);
    Cluster * c = &(*cluster);
    if(!c->is_free_space())
        throw Already_Filled();
    else if(!c->has_capacity(end-begin-1) || c->end()-begin < end-begin)
        throw Range_Too_Big();
    if(c->begin() == begin && c->end() == end) // CASO1: Célula ocupa o cluster inteiro
        cluster = __fill_cluster_with_a_range(cluster, begin, end, id);
    else if(c->begin() == begin && end < c->end()) // CASO2: Célula ocupa o início do cluster
        cluster = __place_range_at_beginning_of_cluster(cluster, begin, end, id);
    else if(c->end() == end && begin > c->begin()) // CASO3: Célula ocupa o fim do cluster
        cluster = __place_range_at_end_of_cluster(cluster, begin, end, id);
    else if(begin > c->begin() && end < c->end()) // CASO4: Célula ocupa o meio do cluster
        cluster = __place_range_at_middle_of_cluster(cluster, begin, end, id);
    return cluster;
}

std::list<Cluster>::iterator Row::insert_range(std::pair<int, int> range, int id)
{
    return insert_range(range.first, range.second, id);
}

void Row::__remove_free_cluster(std::list<Cluster>::iterator cluster)
{
    std::list<Cluster>::iterator next(cluster);
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
    std::list<Cluster>::iterator cluster =  std::find_if(_clusters.begin(), _clusters.end(), Cluster_Has_Id(id));
    std::list<Cluster> new_clusters = cluster->split(id);
    if(new_clusters.empty())
        return __remove_free_cluster(cluster);

    if(cluster != _clusters.begin())
    {
        std::list<Cluster>::iterator previous(cluster);
        previous--;
        if(previous->is_free_space())
            previous->end(new_clusters.front().begin()-1);
    }
    else if(new_clusters.front().begin() != _begin)
        _clusters.insert(cluster, Cluster(_begin, new_clusters.front().begin()-1));

    std::list<Cluster>::iterator next(cluster);
    next++;
    if(next != _clusters.end())
    {
        if(next->is_free_space())
            next->begin(new_clusters.back().end()+1);
    }
    else if(new_clusters.back().end() != _end)
        _clusters.insert(next, Cluster(new_clusters.back().end()+1, _end));
    _clusters.insert(cluster, new_clusters.begin(), new_clusters.end());
    std::list<Cluster>::iterator previous(cluster);
    while(previous != _clusters.begin())
    {
        previous--;
        for(std::list<Range_In_Cluster>::iterator it = previous->ranges().begin(); it != previous->ranges().end(); it++)
            it->cluster(previous);
    }
    _clusters.erase(cluster);
}

std::pair<int, int> Row::get_previous_and_next_free(std::pair<int, int> range, int id)
{
    return get_previous_and_next_free(range.first, range.second, id);
}

std::pair<int, int> Row::get_previous_and_next_free(int begin, int end, int id)
{
    std::list<Cluster>::iterator cluster = _clusters.end();
    for(std::list<Cluster>::iterator it = _clusters.begin(); it != _clusters.end(); it++)
    {
        if(begin >= it->begin() && begin <= it->end())
        {
            if(!it->is_free_space())
                cluster = it;
            else if(end > it->end())
            {
                it++;
                cluster = it;
            } else if(end <= it->end())
            {
                if(it->has_capacity(end-begin+1))
                    return std::make_pair(begin, begin);
            }
            break;
        }
    }
    bool first = false;
    bool second = false;
    std::pair<int, int> near(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    std::list<Cluster>::iterator previous(cluster);
    if(cluster != _clusters.begin())
    {
        previous--;
        while(!previous->has_capacity(end-begin+1) && previous != _clusters.begin())
            previous--;
        if(previous->has_capacity(end-begin+1))
        {
            near.first = previous->end()-(end-begin);
            first = true;
        }
    }
    std::list<Cluster>::iterator next(cluster);
    next++;
    if(next != _clusters.end())
    {
        while(!next->has_capacity(end-begin+1) && next != _clusters.end())
            next++;
        if(next->has_capacity(end-begin+1) && next != _clusters.end())
        {
            near.second = next->begin();
            second = true;
        }
    }

    if(!first && second)
        near.first = near.second;
    else if(first && !second)
        near.second = near.first;

    return near;
}

std::list<Cluster>::iterator Row::__clusterize_with_next(std::list<Cluster>::iterator cluster_it)
{
    std::list<Cluster>::iterator next(cluster_it);
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

std::list<Cluster>::iterator Row::__clusterize_with_previous(std::list<Cluster>::iterator cluster_it)
{
    if(cluster_it == _clusters.begin())
    {
        cluster_it->begin(_begin);
        return cluster_it;
    }
    std::list<Cluster>::iterator previous(cluster_it);
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

std::list<Cluster>::iterator Row::move_cluster_to_right(std::list<Cluster>::iterator cluster_it, int step)
{
    if(step < 1)
        throw Invalid_Step_Size();
    // Checa se tem espaço
    std::list<Cluster>::iterator next(cluster_it);
    next++;
    if(next == _clusters.end())
        throw Not_Enough_Space();
    else if(!next->has_capacity(step))
        throw Not_Enough_Space();

    // Libera espaço na esquerda
    if(cluster_it == _clusters.begin())
        _clusters.insert(cluster_it, Cluster(_begin, _begin+step));

    std::list<Cluster>::iterator previous(cluster_it);
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

std::list<Cluster>::iterator Row::move_cluster_to_left(std::list<Cluster>::iterator cluster_it, int step)
{
    if(step < 1)
        throw Invalid_Step_Size();
    // Checa se tem espaço
    if(cluster_it == _clusters.begin())
        throw Not_Enough_Space();
    else {
        std::list<Cluster>::iterator previous(cluster_it);
        previous--;
        if(!previous->has_capacity(step))
            throw Not_Enough_Space();
    }

    // Libera espaço na direita
    std::list<Cluster>::iterator next(cluster_it);
    next++;

    if(next == _clusters.end())
        _clusters.push_back(Cluster(cluster_it->end() + 1 - step, _end));

    next->begin(next->begin()-step);

    // Muda os limites do cluster
    cluster_it->begin(cluster_it->begin()-step);
    cluster_it->end(cluster_it->end()-step);

    // Diminui o cluster livre à esquerda e se precisar, remove-o
    std::list<Cluster>::iterator previous(cluster_it);
    previous--;
    previous->end(previous->end()-step);
    if(previous->end() < previous->begin())
        _clusters.erase(previous);
    return __clusterize_with_previous(cluster_it);
}

std::list<Cluster>::iterator Row::find_cluster_by_range(std::pair<int, int> range)
{
    return __find_cluster_by_range(range.first, range.second);
}

std::list<Cluster>::iterator Row::find_cluster_by_value(int value)
{
    if(value < _begin || value > _end)
        throw Out_of_Bounds();
    return std::find_if(_clusters.begin(), _clusters.end(), Cluster_Has_Range(value, value));
}

std::list<Cluster>::iterator Row::first_cluster_iterator()
{
    return _clusters.begin();
}

std::list<Cluster>::iterator Row::not_valid_iterator()
{
    return _clusters.end();
}
}
