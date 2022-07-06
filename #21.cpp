/*
This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), 
find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

#include<bits/stdc++.h>
using namespace std;


// Logic: Make a map like the following
// (0, +1), (30, +1), (50, -1), (60, +1), (75, -1), (150, -1)
// 1 meeting, 2 meetings, 1 meeting((0, 50) ended), 2 meetings, 1 meeting((30, 75) ended), 0 meeting ((60, 150) ended)

int minNumOfRooms(vector<vector<int>> lectures){
    int n = lectures.size();
    map<int, int> m;
    for(int i = 0; i < n; i++){
        // = 1 represents lectures[i] has started
        m[lectures[i][0]] = 1; // or m.insert({lectures[i][0], 1})
        // = -1 represents lectures[i] has ended
        m[lectures[i][1]] = -1;
    }
    // Note: Elements are sorted by key by default in map stl
    int curr_meetings = 0;
    int min_rooms_required = 0;
    for(auto i = m.begin(); i != m.end(); i++){
        curr_meetings += i -> second;
        min_rooms_required = max(min_rooms_required, curr_meetings);
    }
    return min_rooms_required;
}