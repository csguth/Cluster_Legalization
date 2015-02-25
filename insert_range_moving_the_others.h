#ifndef INSERT_RANGE_MOVING_THE_OTHERS_H
#define INSERT_RANGE_MOVING_THE_OTHERS_H

#include "row.h"
namespace Overlap_Removal {

class Insert_Range_Moving_The_Others
{
    static const int MAX_TRIES_TO_REMOVE_OVERLAP;
    int __get_left_need(int left_range, Cluster_Iterator cluster_of_left_range, Overlap_Removal::Row &r, std::pair<int, int> range);
    int __get_right_need(int right_range, Cluster_Iterator cluster_of_right_range, Overlap_Removal::Row &r, std::pair<int, int> range);
    bool __move_ranges_to_left(Overlap_Removal::Row &r, int left_range, std::pair<int, int> range);
    bool __move_ranges_to_right(Overlap_Removal::Row &r, int right_range, std::pair<int, int> range);
    bool __try_to_move_first_at_left_to_left_and_first_at_right_to_right(Overlap_Removal::Row & r, std::pair<int, int> range, int id);
    bool __try_unbalanced(Overlap_Removal::Row &r, std::pair<int, int> range, int id);
public:
    bool operator()(std::pair<int, int> range, int id, Overlap_Removal::Row & r);
};
}

#endif // INSERT_RANGE_MOVING_THE_OTHERS_H
