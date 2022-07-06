/*
Problem Description:
This problem was asked by Facebook.

Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.
*/

#include<bits/stdc++.h>
using namespace std;

int MaxProdOfThree(vector<int> nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());

    return max(nums[n-1]*nums[n-2]*nums[n-3], nums[n-1]*nums[0]*nums[1]);
}