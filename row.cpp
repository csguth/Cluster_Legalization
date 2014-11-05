#include "row.h"
namespace Overlap_Removal {

Row::Row(int begin, int end) :_begin(begin), _end(end)
{
    clear();
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

bool Row::insert_range(int begin, int end, int id)
{
    if(begin < _begin || end > _end || end < begin)
        return false;
    std::list<Cluster>::iterator cluster = _clusters.end();
    for(std::list<Cluster>::iterator it = _clusters.begin(); it != _clusters.end(); it++)
    {
        if(begin >= it->begin() && end <= it->end())
        {
            cluster = it;
            break;
        }
    }
    if(cluster == _clusters.end() || !cluster->is_free_space())
        return false;
    Cluster * c = &(*cluster);
    if(c->begin() == begin && c->end() == end) // CASO1: Célula ocupa o cluster inteiro
    {
        c->add_at_end(id, begin, end);

        std::list<Cluster>::iterator previous(cluster);
        if(previous != _clusters.begin()) // se tem anterior
        {
            previous--;
            if(!previous->is_free_space()) // se o anterior está ocupado, clusteriza com o anterior
            {
                previous->end(c->end());
                previous->add_at_end(c->ranges());
                _clusters.erase(cluster);
                cluster = previous;
            }
        }
        std::list<Cluster>::iterator next(cluster);
        next++;
        if(next != _clusters.end())
        {
            if(!next->is_free_space())
            {
                cluster->end(next->end());
                cluster->add_at_end(next->ranges());
                _clusters.erase(next);
            }
        }
    } else if(c->begin() == begin && end < c->end()) // CASO2: Célula ocupa o início do cluster
    {
        int end_before = c->end();
        c->end(end);
        c->add_at_end(id, begin, end);
        std::list<Cluster>::iterator previous(cluster);
        if(previous != _clusters.begin()) // se tem anterior
        {
            previous--;
            if(!previous->is_free_space()) // se o anterior está ocupado, clusteriza com o anterior
            {
                previous->end(c->end());
                previous->add_at_end(c->ranges());
                _clusters.erase(cluster);
                cluster = previous;
            }
        }

        std::list<Cluster>::iterator next(cluster);
        next++;
        _clusters.insert(next, Cluster(end+1, end_before));
    }
    else if(c->end() == end && begin > c->begin()) // CASO3: Célula ocupa o fim do cluster
    {
        int begin_before = c->begin();
        c->begin(begin);
        c->add_at_end(id, begin, end);
        std::list<Cluster>::iterator next(cluster);
        next++;
        if(next != _clusters.end())
        {
            if(!next->is_free_space())
            {
                c->add_at_end(next->ranges());
                c->end(next->end());
                _clusters.erase(next);
            }
        }
        _clusters.insert(cluster, Cluster(begin_before, begin-1));

    } else if(begin > c->begin() && end < c->end()) // CASO4: Célula ocupa o meio do cluster
    {
        int begin_before = c->begin();
        int end_before = c->end();
        std::list<Cluster>::iterator next(cluster);
        next++;
        _clusters.insert(cluster, Cluster(begin_before, begin-1));
        _clusters.insert(next, Cluster(end+1, end_before));
        c->begin(begin);
        c->end(end);
        c->add_at_end(id, begin, end);
    }
    return true;
}

bool Row::insert_range(std::pair<int, int> range, int id)
{
    return insert_range(range.first, range.second, id);
}

bool Row::remove_by_id(int id)
{
    std::list<Cluster>::iterator cluster = _clusters.end();
    for(std::list<Cluster>::iterator it = _clusters.begin(); it != _clusters.end(); it++)
    {
        if(it->has(id))
        {
            cluster = it;
            break;
        }
    }
    if(cluster == _clusters.end())
        return false;
    std::list<Cluster> new_clusters = cluster->split(id);
    std::list<Cluster>::iterator first_new = new_clusters.begin();
    std::list<Cluster>::iterator last_new = new_clusters.end();
    std::list<Cluster>::iterator last_element(last_new);
    last_element--;
    std::list<Cluster>::iterator previous(cluster);
    std::list<Cluster>::iterator next(cluster);
    next++;
    if(cluster->number_of_ranges()==1 && cluster->has(id))
    {
        if(next == _clusters.end())
        {
            previous--;
            previous->end(cluster->end());
            _clusters.erase(cluster);
        } else {
            if(cluster == _clusters.begin())
            {
                next->begin(cluster->begin());
                _clusters.erase(cluster);
            } else {
                previous--;
                previous->end(next->end());
                _clusters.erase(cluster);
                _clusters.erase(next);
            }
        }
        return true;
    }
    else
    {
        if(cluster != _clusters.begin())
        {
            previous--;
            if(previous->is_free_space() && first_new->is_free_space())
            {
                previous->end(first_new->end());
                first_new++;
            }
        }
        if(next != _clusters.end())
        {
            if(last_element->is_free_space() && next->is_free_space())
            {
                last_new = last_element;
                next->begin(last_element->begin());
            }
        }
    }
    _clusters.insert(cluster, first_new, last_new);
    _clusters.erase(cluster);
    return true;
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
}
