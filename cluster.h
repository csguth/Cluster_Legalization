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
    int begin() const;
    int end() const;
    void move_to_right(int step);
    void move_to_left(int step);
};

class Range_Has_Id {

    int _id;
public:
    Range_Has_Id(int id):_id(id){

    }
    bool operator()(const Range_In_Cluster & r)
    {
        return r.id() == _id;
    }
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
    const std::list<Range_In_Cluster> &ranges() const;
    std::list<Range_In_Cluster> & ranges();

    std::list<Cluster> split(int id);
    bool has_capacity(int number_of_ranges);
    int size();

    int free_space_at_right();
    int free_space_at_left();
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

#endif // CLUSTER_H
