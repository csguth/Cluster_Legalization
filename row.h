#ifndef ROW_H
#define ROW_H

#include "cluster.h"
#include <list>
#include <cstdlib>
#include <limits>

namespace Overlap_Removal {

class Row
{
    int _begin;
    int _end;
    std::list<Cluster> _clusters;
public:
    Row(int begin, int end);
    void clear();
    int begin();
    int end();
    int number_of_clusters();
    const Cluster & cluster(int index);
    bool insert_range(int begin, int end, int id);
    bool insert_range(std::pair<int, int> range, int id);
    bool remove_by_id(int id);
    std::pair<int, int> get_previous_and_next_free(std::pair<int, int> range, int id);
    std::pair<int, int> get_previous_and_next_free(int begin, int end, int id);
};
}

#endif // ROW_H
