/*
This problem was asked by Amazon.

An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than linear time. 
If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.
*/

// Note: Similar problems - 311, 203

/*
Logic:
Without finding the pivot point , from where the array is rotated...
there are only two possibilities ..
1.The mid of our search space will be greater than start of our search space.

-> now array will be sorted from start to mid
-> here are two possibilities ...target can be between start to mid or on the right part of mid.
2.The mid of our search space will be smaller than start of our search space

-> now the array will be sorted from mid to end
-> here are other two possibilities ...target can be in between the mid to end or on the left part of mid
*/

// Tip: Work on couple of examples
#include<bits/stdc++.h>
using namespace std;


int find(vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        if(left == mid){
            left += 1;
            continue;
        }
        if(nums[mid] > nums[left]){
            if(target >= nums[left] and target < nums[mid]) right = mid -1;
            else left = mid + 1;
        }
        else{
            if(target <= nums[right] and target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}

