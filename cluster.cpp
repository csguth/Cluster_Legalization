#include "cluster.h"
namespace Overlap_Removal {

Cluster::Cluster(int begin, int end):_begin(begin), _end(end)
{
}

int Cluster::begin() const
{
    return _begin;
}

int Cluster::end() const
{
    return _end;
}

void Cluster::begin(int begin)
{
    _begin = begin;
}

void Cluster::end(int end)
{
    _end = end;
}

bool Cluster::is_free_space() const
{
    return  !_ranges.size();
}

int Cluster::number_of_ranges() const
{
    return _ranges.size();
}

bool Cluster::has(int id) const
{
    for(std::list<Range_In_Cluster>::const_iterator it = _ranges.begin(); it != _ranges.end(); it++)
        if(it->id() == id)
            return true;
    return false;
}

void Cluster::add_at_end(int cell_id, int begin, int end)
{
    _ranges.push_back(Range_In_Cluster(cell_id, begin, end));
    _end = end;
}

void Cluster::add_at_end(const std::list<Range_In_Cluster> &cells)
{
    _ranges.insert(_ranges.end(), cells.begin(), cells.end());
    _end = _ranges.back().end();
}

const std::list<Range_In_Cluster> &Cluster::ranges() const
{
    return _ranges;
}

std::list<Range_In_Cluster> &Cluster::ranges()
{
    return _ranges;
}


std::list<Cluster> Cluster::split(int id)
{
    std::list<Cluster> result;
    bool created = false;
    for(std::list<Range_In_Cluster>::iterator it = _ranges.begin(); it != _ranges.end(); it++)
    {
        if(it->id() == id)
        {
            result.push_back(Cluster(it->begin(), it->end()));
            created = false;
        }
        else
        {
            Cluster * last = &result.back();
            if(!created)
            {
                result.push_back(Cluster(it->begin(), it->end()));
                last = &result.back();
                created = true;
            }
            last->end(it->end());
            last->add_at_end(it->id(), it->begin(), it->end());
        }
    }
    return result;
}

bool Cluster::has_capacity(int size)
{
    if(_ranges.empty())
        return (_end-_begin+1) >= size;
    return  false;
}

int Cluster::size()
{
    return _end-_begin+1;
}


Range_In_Cluster::Range_In_Cluster(int id, int begin, int end) : _id(id), _begin(begin), _end(end)
{

}


int Range_In_Cluster::id() const
{
    return _id;
}

int Range_In_Cluster::begin() const
{
    return _begin;
}

int Range_In_Cluster::end() const
{
    return _end;
}

void Range_In_Cluster::move_to_right(int step)
{
    _begin += step;
    _end += step;
}

void Range_In_Cluster::move_to_left(int step)
{
    _begin -= step;
    _end -= step;
}


}
