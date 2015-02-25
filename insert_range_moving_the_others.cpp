#include "insert_range_moving_the_others.h"

const int Overlap_Removal::Insert_Range_Moving_The_Others::MAX_TRIES_TO_REMOVE_OVERLAP = 100;

bool Overlap_Removal::Insert_Range_Moving_The_Others::__move_ranges_to_left(Overlap_Removal::Row &r, int left_range, std::pair<int, int> range)
{
    Cluster_Iterator left_cluster = r.find_cluster_by_id(left_range);
    int min_step_to_solve_overlap = 0;
    for(std::list<Overlap_Removal::Range_In_Cluster>::const_iterator the_range = left_cluster->ranges().begin(); the_range != left_cluster->ranges().end(); the_range++)
    {
        if(the_range->id() == left_range)
        {
            min_step_to_solve_overlap = the_range->end()-range.first+1;
            break;
        }
    }
    int free_space_on_left = r.free_space_on_left(left_cluster);
    int actual_step = std::min(free_space_on_left, min_step_to_solve_overlap);
    actual_step = std::max(actual_step, 0);
    if(actual_step != 0)
        r.split_cluster_and_move_to_left(left_cluster, left_range, actual_step);
    return actual_step >= min_step_to_solve_overlap;
}

bool Overlap_Removal::Insert_Range_Moving_The_Others::__move_ranges_to_right(Overlap_Removal::Row &r, int right_range, std::pair<int, int> range)
{
    Cluster_Iterator right_cluster = r.find_cluster_by_id(right_range);
    int min_step_to_solve_overlap = 0;
    for(std::list<Overlap_Removal::Range_In_Cluster>::const_iterator the_range = right_cluster->ranges().begin(); the_range != right_cluster->ranges().end(); the_range++)
    {
        if(the_range->id() == right_range)
        {
            min_step_to_solve_overlap = range.second-the_range->begin()+1;
            break;
        }
    }
    int free_space_on_right = r.free_space_on_right(right_cluster);
    int actual_step = std::min(free_space_on_right, min_step_to_solve_overlap);
    actual_step = std::max(actual_step, 0);
    if(actual_step != 0)
        r.split_cluster_and_move_to_right(right_cluster, right_range, actual_step);
    return actual_step >= min_step_to_solve_overlap;
}

bool Overlap_Removal::Insert_Range_Moving_The_Others::__try_to_move_first_at_left_to_left_and_first_at_right_to_right(Overlap_Removal::Row &r, std::pair<int, int> range, int id)
{
    Overlap_Removal::Row clone(r);
    Cluster_Iterator cluster_at_left = clone.find_cluster_by_value(range.first);
    Cluster_Iterator cluster_at_end = clone.find_cluster_by_value(range.second);

    int left_range = clone.first_range_at_left_of(range);
    int right_range = clone.first_range_at_right_of(range);
    Cluster_Iterator cluster_of_left_range;
    Cluster_Iterator cluster_of_right_range;

    if(left_range != -1)
        cluster_of_left_range = (clone.find_cluster_by_id(left_range));
    else
        cluster_of_left_range = cluster_at_left;

    if(right_range != -1)
        cluster_of_right_range = clone.find_cluster_by_id(right_range);
    else
        cluster_of_right_range = cluster_at_end;


    int left_need = __get_left_need(left_range, cluster_of_left_range, clone,range);
    int right_need = __get_right_need(right_range, cluster_of_right_range, clone,range);

    int total_free_space_on_left = clone.total_free_space_on_left(cluster_at_left, range.first-1);
    int total_free_space_on_right = clone.total_free_space_on_right(cluster_at_end, range.second);
    if(total_free_space_on_left >= left_need && total_free_space_on_right >= right_need)
    {
        int tries = 0;
        bool solved = false;
        while(!solved && tries < MAX_TRIES_TO_REMOVE_OVERLAP)
        {
            tries++;
            int left_range = clone.first_range_at_left_of(range);
            if(left_range == -1)
                break;
            solved = __move_ranges_to_left(clone,left_range, range);
        }

        if(tries >= MAX_TRIES_TO_REMOVE_OVERLAP)
            return false;

        solved = false;
        tries = 0;
        while(!solved && tries < MAX_TRIES_TO_REMOVE_OVERLAP)
        {
            tries++;
            int right_range = clone.first_range_at_right_of(range);
            if(right_range == -1)
                break;
            solved = __move_ranges_to_right(clone,right_range, range);
        }
        if(tries >= MAX_TRIES_TO_REMOVE_OVERLAP)
            return false;

        clone.insert_range(range, id);
        r = clone;
        return true;
    }
    return false;
}

int Overlap_Removal::Insert_Range_Moving_The_Others::__get_left_need(int left_range, Cluster_Iterator cluster_of_left_range, Overlap_Removal::Row &r, std::pair<int, int> range)
{
    int left_need = 0;
    Cluster_Iterator current(cluster_of_left_range);
    while(current->end() >= range.first)
    {
        for(std::list<Range_In_Cluster>::const_iterator the_range = current->ranges().begin(); the_range != current->ranges().end(); the_range++)
        {
            int overlap_begin = std::max(the_range->begin(), range.first);
            int overlap_end = std::min(the_range->end(), range.second);
            int overlap_size = overlap_end-overlap_begin+1;
            if(overlap_size > 0)
                left_need += overlap_size;
            if(the_range->id() == left_range)
                break;
        }
        if(current == r.first_cluster_iterator())
            break;
        current--;
    }

    return left_need;
}

int Overlap_Removal::Insert_Range_Moving_The_Others::__get_right_need(int right_range, Cluster_Iterator cluster_of_right_range, Overlap_Removal::Row &r, std::pair<int, int> range)
{
    Cluster_Iterator current = cluster_of_right_range;
    bool count = false;
    int right_need = 0;
    while(current != r.not_valid_iterator() && current->begin() <= range.second)
    {
        for(std::list<Range_In_Cluster>::const_iterator the_range = current->ranges().begin(); the_range != current->ranges().end(); the_range++)
        {
            if(the_range->id() == right_range)
                count = true;
            if(count)
            {
                int overlap_begin = std::max(the_range->begin(), range.first);
                int overlap_end = std::min(the_range->end(), range.second);
                int overlap_size = overlap_end-overlap_begin+1;
                if(overlap_size > 0)
                    right_need += overlap_size;
            }
        }
        current++;
    }
    return right_need;
}

bool Overlap_Removal::Insert_Range_Moving_The_Others::__try_unbalanced(Overlap_Removal::Row &r, std::pair<int, int> range, int id)
{
    Overlap_Removal::Row clone(r);
    Cluster_Iterator cluster_at_left = clone.find_cluster_by_value(range.first);
    Cluster_Iterator cluster_at_end = clone.find_cluster_by_value(range.second);

    int left_range = clone.first_range_at_left_of(range);
    int right_range = clone.first_range_at_right_of(range);
    Cluster_Iterator cluster_of_left_range;
    Cluster_Iterator cluster_of_right_range;

    if(left_range != -1)
        cluster_of_left_range = (clone.find_cluster_by_id(left_range));
    else
        cluster_of_left_range = cluster_at_left;

    if(right_range != -1)
        cluster_of_right_range = clone.find_cluster_by_id(right_range);
    else
        cluster_of_right_range = cluster_at_end;


    int left_space =  clone.total_free_space_on_left(cluster_at_left, range.first-1);
    int right_space =  clone.total_free_space_on_right(cluster_at_end, range.second);

    int left_filled = 0;
    int right_filled  = 0;

    int new_left = -1;
    int new_right = -1;
    if(left_space < __get_left_need(left_range, cluster_of_left_range, clone, range)){
        Cluster_Iterator current(cluster_of_left_range);
        while(current != clone.not_valid_iterator() && current->begin() <= range.second)
        {
            for(std::list<Overlap_Removal::Range_In_Cluster>::const_iterator the_range = current->ranges().begin(); the_range != current->ranges().end(); the_range++)
            {
                int overlap_begin = std::max(the_range->begin(), range.first);
                int overlap_end = std::min(the_range->end(), range.second);
                int overlap_size = overlap_end-overlap_begin+1;
                if(left_space - left_filled >= overlap_size && new_right == -1)
                {
                    new_left = the_range->id();
                    left_filled += std::max(0, overlap_size);
                } else
                {
                    if(new_right == -1)
                        new_right = the_range->id();
                    if(right_space-right_filled >= overlap_size)
                        right_filled += overlap_size;
                    else return false;
                }
            }
            current++;
        }
    } else if(right_space < __get_right_need(right_range, cluster_of_right_range, clone, range))
    {
        Cluster_Iterator current(cluster_of_right_range);
        while(current->end() >= range.first)
        {
            for(std::list<Overlap_Removal::Range_In_Cluster>::const_reverse_iterator the_range = current->ranges().rbegin(); the_range != current->ranges().rend(); the_range++)
            {
                int overlap_begin = std::max(the_range->begin(), range.first);
                int overlap_end = std::min(the_range->end(), range.second);
                int overlap_size = overlap_end-overlap_begin+1;
                if(right_space - right_filled >= overlap_size && new_left == -1)
                {
                    new_right = the_range->id();
                    right_filled += std::max(0, overlap_size);
                } else
                {
                    if(new_left == -1)
                        new_left = the_range->id();
                    if(left_space-left_filled >= overlap_size)
                        left_filled += overlap_size;
                    else return false;
                }
            }
            if(current == clone.first_cluster_iterator())
                break;
            current--;
        }
    }
    if(left_range == new_left && right_range == new_right)
        return false;

    int tries = 0;
    if(new_right != -1)
    {
        tries = 0;
        bool solved = false;
        while(!solved && tries < MAX_TRIES_TO_REMOVE_OVERLAP)
        {
            tries++;
            solved = __move_ranges_to_right(clone, new_right, range);
        }
        if(tries >= MAX_TRIES_TO_REMOVE_OVERLAP)
            return false;
    }
    if(new_left != -1)
    {
        tries = 0;
        bool solved = false;
        while(!solved && tries < MAX_TRIES_TO_REMOVE_OVERLAP)
        {
            tries++;
            solved = __move_ranges_to_left(clone, new_left, range);
        }
        if(tries >= MAX_TRIES_TO_REMOVE_OVERLAP)
            return false;
    }

    clone.insert_range(range, id);
    // Se deu certo
    r = clone;
    return true;

}

bool Overlap_Removal::Insert_Range_Moving_The_Others::operator()(std::pair<int, int> range, int id, Overlap_Removal::Row &r)
{
    if(__try_to_move_first_at_left_to_left_and_first_at_right_to_right(r, range, id))
        return true;
    return __try_unbalanced(r, range, id);
}
