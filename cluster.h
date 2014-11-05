#ifndef CLUSTER_H
#define CLUSTER_H
#include <list>
#include <algorithm>

namespace Overlap_Removal {



class Range_In_Cluster {
    int _id;
    int _begin;
    int _end;
public:
    Range_In_Cluster(int id, int begin, int end);
    int id() const;
    int begin();
    int end();
};



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
    void add_at_end(int cell_id, int begin, int end);
    void add_at_end(const std::list<Range_In_Cluster> &ranges);
    const std::list<Range_In_Cluster> &ranges();
    std::list<Cluster> split(int id);
    bool has_capacity(int number_of_ranges);
    int size();
};
}

#endif // CLUSTER_H
