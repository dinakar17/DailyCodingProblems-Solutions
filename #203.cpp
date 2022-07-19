/*
This problem was asked by Uber.

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. 
Find the minimum element in O(log N) time. You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.
*/

#include<bits/stdc++.h>
using namespace std;


// Logic: Work on some examples and formulate the necessary conditions (take note of *right -= 1* condition)
// The below code works no matter how many number of times the sorted array is rotated.
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
int minElement(vector<int>& nums){
    int left = 0, right = nums.size() - 1;
    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] > nums[right]) left = mid + 1;
        // else if(nums[mid] < nums[left]) right = mid; // this one works too
        else if(nums[mid] < nums[right] ) right = mid;
        else right -= 1;
    }
    return nums[left];
}

int main(){
    vector<int> nums = {5, 7, 10, 3, 4};
    cout << minElement(nums) << " ";
    return 0;
}