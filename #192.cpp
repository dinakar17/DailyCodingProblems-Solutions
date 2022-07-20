/*
This problem was asked by Google.

You are given an array of nonnegative integers. 
Let's say you start at the beginning of the array and are trying to advance to the end. 
You can advance at most, the number of steps that you're currently on. 
Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.
*/

#include<bits/stdc++.h>
using namespace std;


// Reference: Elements of Fundamental Programming Book
bool CanReach(vector<int>& nums){
    int maxReach = 0, last_idx = nums.size() - 1;
    for(int i = 0; i <= maxReach and maxReach < last_idx; i++){
        maxReach = max(maxReach, i + nums[i]);
    }
    return maxReach >= last_idx;
}