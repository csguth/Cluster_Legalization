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
    return std::find_if(_ranges.begin(), _ranges.end(), Range_Has_Id(id)) != _ranges.end();
}

void Cluster::add_at_end(Range_In_Cluster range)
{
    int new_begin = _end - _begin + 1;
    int size = range.end() - range.begin();
    if(_ranges.empty())
        new_begin = 0;
    int new_end = new_begin + size;
    range.begin(new_begin);
    range.end(new_end);
    _ranges.push_back(range);
    _end = range.end();
}

void Cluster::add_at_end(const std::list<Range_In_Cluster> &cells)
{
    for(std::list<Range_In_Cluster>::const_iterator it = cells.begin(); it != cells.end(); it++)
        this->add_at_end((*it));
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
    _ranges.remove_if(Range_Has_Id(id));
    if(_ranges.empty())
        return result;
    int last_end = _ranges.front().begin()-1;
    for(std::list<Range_In_Cluster>::iterator it = _ranges.begin(); it != _ranges.end(); it++)
    {
        if(result.empty())
            result.push_back(Cluster(it->begin(), it->end()));
        if(last_end == it->begin()-1)
        {
            std::list<Cluster>::iterator end = result.end();
            end--;
            Cluster & last = (*end);
            Range_In_Cluster range(it->id(), it->begin(), it->end());
            range.cluster(end);
            last.add_at_end(range);
        } else {
            result.push_back(Cluster(last_end+1, it->begin()-1));
            result.push_back(Cluster(it->begin(), it->end()));
            std::list<Cluster>::iterator end = result.end();
            end--;
            Cluster & last = (*end);
            Range_In_Cluster range(it->id(), it->begin(), it->end());
            range.cluster(end);
            last.add_at_end(range);
        }
        last_end = it->end();
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

void Cluster::set_cluster_iterator_to_all_ranges(std::list<Cluster>::iterator it)
{
    for(std::list<Range_In_Cluster>::iterator range = _ranges.begin(); range != _ranges.end(); range++)
        range->cluster(it);
}



}
