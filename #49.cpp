/*
This problem was asked by Amazon.

Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, 
since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

Do this in O(N) time.
*/

#include<bits/stdc++.h>
using namespace std;

int maxContiguousSubArray(vector<int> nums){
    int n = nums.size();
    int global_sum = INT_MIN;
    int local_sum = 0;
    for(int i = 0; i < n; i++){
        local_sum += nums[i];
        if(local_sum > global_sum) global_sum = local_sum;
        if(local_sum < 0) local_sum = 0;
    }
    return global_sum;
}