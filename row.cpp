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
    for(Cluster_Iterator it = other._clusters.begin(); it != other._clusters.end(); it++)
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
    if(!cluster->is_free_space())
        throw Already_Filled();
    else if(!cluster->has_capacity(end-begin-1) || cluster->end()-begin < end-begin)
        throw Range_Too_Big();
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

std::pair<Cluster_Iterator, Cluster_Iterator> Row::get_previous_and_next_free(std::pair<int, int> range)
{
    return get_previous_and_next_free(range.first, range.second);
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

std::pair<Cluster_Iterator, Cluster_Iterator> Row::get_previous_and_next_free(int begin, int end)
{
    Cluster_Iterator cluster = find_cluster_by_value(begin);
    if(cluster != _clusters.end())
    {
        if(cluster->is_free_space() && cluster->end() >= end)
            return std::make_pair(cluster, cluster);
        else if(cluster->is_free_space() && cluster->end() < end)
            cluster++;
    }
    std::pair<Cluster_Iterator, Cluster_Iterator> near(_clusters.end(), _clusters.end());
    Cluster_Iterator left = __find_first_cluster_on_the_left(cluster, end-begin+1);
    Cluster_Iterator right = __find_first_cluster_on_the_right(cluster, end-begin+1);
    if(left == _clusters.end() && right != _clusters.end())
        left = right;
    else if(right == _clusters.end() && left != _clusters.end())
        right = left;
    return std::make_pair(left, right);
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
}
