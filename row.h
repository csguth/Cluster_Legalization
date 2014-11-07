#ifndef ROW_H
#define ROW_H

#include "cluster.h"
#include <list>
#include <cstdlib>
#include <limits>
#include <exception>
#include "exception.h"

namespace Overlap_Removal {

class Row
{
    int _begin;
    int _end;
    std::list<Cluster> _clusters;
    std::list<Cluster>::iterator __fill_cluster_with_a_range(std::list<Cluster>::iterator cluster, int begin, int end, int id);
    std::list<Cluster>::iterator __place_range_at_beginning_of_cluster(std::list<Cluster>::iterator cluster, int begin, int end, int id);
    std::list<Cluster>::iterator __place_range_at_end_of_cluster(std::list<Cluster>::iterator cluster, int begin, int end, int id);
    std::list<Cluster>::iterator __place_range_at_middle_of_cluster(std::list<Cluster>::iterator cluster, int begin, int end, int id);
    std::list<Cluster>::iterator __find_cluster_by_range(int begin, int end);


    // CLUSTERIZATION
    std::list<Cluster>::iterator __clusterize_with_next(std::list<Cluster>::iterator cluster_it);
    std::list<Cluster>::iterator __clusterize_with_previous(std::list<Cluster>::iterator cluster_it);
    void __remove_free_cluster(std::list<Cluster>::iterator cluster);


public:
    Row(int begin, int end);
    void clear();
    int begin();
    int end();
    int number_of_clusters();
    const Cluster & cluster(int index);
    std::list<Cluster>::iterator insert_range(int begin, int end, int id);
    std::list<Cluster>::iterator insert_range(std::pair<int, int> range, int id);
    void remove_by_id(int id);
    std::pair<int, int> get_previous_and_next_free(std::pair<int, int> range, int id);
    std::pair<int, int> get_previous_and_next_free(int begin, int end, int id);
    std::list<Cluster>::iterator move_cluster_to_right(std::list<Cluster>::iterator cluster_it, int step);
    std::list<Cluster>::iterator move_cluster_to_left(std::list<Cluster>::iterator cluster_it, int step);
    std::list<Cluster>::iterator find_cluster_by_range(std::pair<int, int> range);
    std::list<Cluster>::iterator find_cluster_by_value(int value);
    std::list<Cluster>::iterator not_valid_iterator();
};
}

#endif // ROW_H
