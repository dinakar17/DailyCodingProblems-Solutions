/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Sumo Logic.

Given a array that's sorted but rotated at some unknown pivot, in which all elements are distinct, find a "peak" element in O(log N) time.

An element is considered a peak if it is greater than both its left and right neighbors. It is guaranteed that the first and last elements are lower than all others.
*/

#include<bits/stdc++.h>
using namespace std;

// Logic: {6, 7, 8, 9, 10, 1, 2, 3}, {4, 5, 1, 2, 3} {5, 6, 1, 2, 3, 4}. Work on these three examples and
// formulate the required conditions

int maxElement(vector<int>& nums){
    int l = 0, r = nums.size() - 1;
    while(l < r){
        int m = (l + r) / 2;
        if(nums[l] < nums[m]) l = m;
        else if(nums[l] > nums[m]) r = m-1;
        else l += 1;
    }
    return nums[l];
}

int main(){
    vector<int> nums = {6, 7, 8, 9, 10, 1, 2, 3};
    cout << maxElement(nums) << " ";
    return 0;
}