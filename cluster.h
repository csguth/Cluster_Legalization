#ifndef CLUSTER_H
#define CLUSTER_H
#include <list>
#include <algorithm>
#include "range_in_cluster.h"

namespace Overlap_Removal {


class Range_In_Cluster;
class Cluster
{
    int _begin;
    int _end;
    std::list<Range_In_Cluster> _ranges;
public:
    Cluster(int begin, int end);
    int begin() const;
    int end() const;
    void begin(int begin);
    void end(int end);
    bool is_free_space() const;
    int number_of_ranges() const;
    bool has(int id) const;
    void add_at_end(Range_In_Cluster range);
    void add_at_end(const std::list<Range_In_Cluster> &ranges);
    const std::list<Range_In_Cluster> &ranges() const;
    std::list<Range_In_Cluster> & ranges();

    std::list<Cluster> split(int id);
    bool has_capacity(int number_of_ranges);
    int size();

    void set_cluster_iterator_to_all_ranges(std::list<Cluster>::iterator it);
};

class Cluster_Has_Range {
    int _begin;
    int _end;
public:
    Cluster_Has_Range(int begin, int end):_begin(begin), _end(end){}
    bool operator()(const Cluster & c) {
        return _begin >= c.begin() && _end <= c.end();
    }
};

class Cluster_Has_Id {
    int _id;
public:
    Cluster_Has_Id(int id):_id(id){

    }
    bool operator()(const Cluster & c)
    {
        return c.has(_id);
    }
};


}

typedef std::list<Overlap_Removal::Cluster>::iterator Cluster_Iterator;


#endif // CLUSTER_H
