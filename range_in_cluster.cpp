#include "range_in_cluster.h"

namespace Overlap_Removal {
Range_In_Cluster::Range_In_Cluster(int id, int begin, int end) : _id(id), _begin(begin), _end(end), _cluster(NULL)
{

}


int Range_In_Cluster::id() const
{
    return _id;
}

int Range_In_Cluster::begin() const
{
    return _begin + _cluster->begin();
}

int Range_In_Cluster::end() const
{
    return _end + _cluster->begin();
}

void Range_In_Cluster::id(int id)
{
    _id = id;
}

void Range_In_Cluster::begin(int begin)
{
    _begin = begin;
}

void Range_In_Cluster::end(int end)
{
    _end = end;
}

void Range_In_Cluster::cluster(std::list<Cluster>::iterator c)
{
    _cluster = c;
}

std::list<Cluster>::iterator Range_In_Cluster::cluster() const
{
    return _cluster;
}

Range_Has_Id::Range_Has_Id(int id):_id(id)
{

}

bool Range_Has_Id::operator()(const Range_In_Cluster &r)
{
    return r.id() == _id;
}

}
