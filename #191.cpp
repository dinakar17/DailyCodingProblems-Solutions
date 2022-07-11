/*
This problem was asked by Stripe.

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Intervals can "touch", such as [0, 1] and [1, 2], but they won't be considered overlapping.

For example, given the intervals (7, 9), (2, 4), (5, 8), return 1 as the last interval can be removed and the first two won't overlap.

The intervals are not necessarily sorted in any order.
*/

//Opposite Problem: Find maximal number of intervals that are non-overlapping

#include<bits/stdc++.h>
using namespace std;

// Note: Visualize interval problems on scale from 1 to max element in the intervals.

// Sort the intervals by their start time
int eraseOverlapIntervals(vector<vector<int>>& intervals){
    // Sorting is the most important step
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();

    int prev_end = intervals[0][1];
    int remove_count = 0;
    for(int i = 1; i < n; i++){
        int curr_start = intervals[i][0];
        int curr_end = intervals[i][1];
        // curr_start < prev_end => The intervals are overlapping
        if(curr_start < prev_end){
            remove_count++;
            // Ex: In [1, 100], [1, 11], [2, 12], [11, 22]
            // i = 1 => prev_end = 100 (should be 11); i = 2 => prev_end = 100 (should be 11) ; i = 3 => prev_end = 100 (should be 11)
            // this excludes [11, 22] from the non-overlapping intervals. 
            prev_end = min(curr_end, prev_end);
            // However, we do not have these scenarios when the intervals are sorted by their end time.
        }
        else{
            prev_end = curr_end;
        }
    }
    return remove_count;
}

// Sort the intervals by their end time
int eraseOverlapIntervals(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) -> bool{return a[1] < b[1]});
    int n = intervals.size();

    int prev_end = intervals[0][1];
    int remove_count = 0;
    for(int i = 0; i < n; i++){
        int curr_start = intervals[i][0];
        int curr_end = intervals[i][1];
        // The intervals are non-overlapping
        if(curr_start >= prev_end) prev_end = curr_end;
        else remove_count++;
    }
    return remove_count;
}

// Note: For merging intervals, sorting by the start time would be easy and for counting non-overlapping intervals, sorting the
// intervals by the end time would be easier to comprehend.