/*
This problem was asked by Microsoft.

Given an array of numbers, find the length of the longest increasing subsequence in the array. 
The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15], 
the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
*/

#include<bits/stdc++.h>
using namespace std;

// Logic: Try to approach the solution for the problem in sub-problematic way i.e., in the above example
// consider [0, 8, 4, 12] for asserting a value (LIS[i]) to 12 we need to go through the elements that are present before it i.e., for "i" go through 0, i-1


int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    vector<int> LIS(n, 1);
    // Default length is 1
    int result = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                LIS[i] = max(LIS[i], LIS[j] + 1);
                result = max(LIS[i], result);
            }
        }
    }
    // return *max_element(LIS.begin(), LIS.end());
    return result;
}