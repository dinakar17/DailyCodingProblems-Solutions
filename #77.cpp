/*
Problem Description:
This problem was asked by Snapchat.

Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].
*/

#include <bits/stdc++.h>
using namespace std;

// Logic: Sort the intervals by the start value (end value doesn't work (Work on a number line to realize this))
// Fact: For finding non-overlapping intervals one should sort the intervals by their end value
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // Use starting values of the intervals for sorting
    sort(intervals.begin(), intervals.end());
    int prev_start = intervals[0][0], prev_end = intervals[0][1];
    int n = intervals.size();
    vector<vector<int>> merged_intervals;
    for (int i = 0; i < n; i++)
    {
        int curr_start = intervals[i][0];
        int curr_end = intervals[i][1];
        // if the current and previous interval is overlapping
        if (curr_start <= prev_end)
        {
            // For example, if prev_interval = [0, "6"] and curr_interval = [1, "4"]
            prev_end = max(prev_end, curr_end);
        }
        else
        {
            merged_intervals.push_back({prev_start, prev_end});
            prev_start = curr_start, prev_end = curr_end;
        }
    }
    merged_intervals.push_back({prev_start, prev_end});
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // Use starting values of the intervals for sorting
    sort(intervals.begin(), intervals.end());

    int n = intervals.size();
    vector<vector<int>> merged_intervals;

    for (int i = 0; i < n; i++){
        // Here merged_intervals.back()[1] == prev_end && intervals[i][0] == curr_start (alternative & opposite to 28th line)
        if(merged_intervals.empty() or merged_intervals.back()[1] < intervals[i][0]){
            merged_intervals.push_back(intervals[i]);
        }
        else{
            // prev_end = max(prev_end, curr_end) (alternative & opposite to 31st line)
            merged_intervals.back()[1] = max(merged_intervals.back()[1], intervals[i][1]);
        }
    }
    return merged_intervals;
}