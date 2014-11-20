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
    Cluster_Iterator __fill_cluster_with_a_range(Cluster_Iterator cluster, int begin, int end, int id);
    Cluster_Iterator __place_range_at_beginning_of_cluster(Cluster_Iterator cluster, int begin, int end, int id);
    Cluster_Iterator __place_range_at_end_of_cluster(Cluster_Iterator cluster, int begin, int end, int id);
    Cluster_Iterator __place_range_at_middle_of_cluster(Cluster_Iterator cluster, int begin, int end, int id);
    Cluster_Iterator __find_cluster_by_range(int begin, int end);


    // CLUSTERIZATION
    void __remove_free_cluster(Cluster_Iterator cluster);
    Cluster_Iterator __clusterize_with_next(Cluster_Iterator cluster_it);
    Cluster_Iterator __clusterize_with_previous(Cluster_Iterator cluster_it);
    Cluster_Iterator __find_first_cluster_on_the_left(Cluster_Iterator cluster, int size);
    Cluster_Iterator __find_first_cluster_on_the_right(Cluster_Iterator cluster, int size);

public:
    Row(int begin, int end);
    Row(Row & other);
    void clear();
    int begin();
    int end();
    int number_of_clusters();
    const Cluster & cluster(int index);
    Cluster_Iterator insert_range_in_cluster(Cluster_Iterator cluster, std::pair<int, int> range, int id);
    Cluster_Iterator insert_range(int begin, int end, int id);
    Cluster_Iterator insert_range(std::pair<int, int> range, int id);
    void remove_by_id(int id);
    std::pair<Cluster_Iterator, Cluster_Iterator> get_previous_and_next_free(std::pair<int, int> range);
    std::pair<Cluster_Iterator, Cluster_Iterator> get_previous_and_next_free(int begin, int end);
    Cluster_Iterator move_cluster_to_right(Cluster_Iterator cluster_it, int step);
    Cluster_Iterator move_cluster_to_left(Cluster_Iterator cluster_it, int step);
    Cluster_Iterator find_cluster_by_range(std::pair<int, int> range);
    Cluster_Iterator find_cluster_by_value(int value);
    Cluster_Iterator first_cluster_iterator();
    Cluster_Iterator not_valid_iterator();
};
}

#endif // ROW_H
