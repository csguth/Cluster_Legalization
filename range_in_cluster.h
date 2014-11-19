#ifndef RANGE_IN_CLUSTER_H
#define RANGE_IN_CLUSTER_H

#include "cluster.h"

namespace Overlap_Removal {


class Cluster;
class Range_In_Cluster {
    int _id;
    int _begin;
    int _end;
    std::list<Cluster>::iterator _cluster;
public:
    Range_In_Cluster(int id, int begin, int end);
    int id() const;
    int begin() const;
    int end() const;

    void id(int id);
    void begin(int begin);
    void end(int end);
    void cluster(std::list<Cluster>::iterator c);
    std::list<Cluster>::iterator cluster() const;
};

class Range_Has_Id {

    int _id;
public:
    Range_Has_Id(int id);
    bool operator()(const Range_In_Cluster & r);

};



}
#endif // RANGE_IN_CLUSTER_H
