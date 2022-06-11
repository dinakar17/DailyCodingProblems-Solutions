/* 

Problem Description:

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, 
compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and 
you do not need to store the results. You can simply print them out as you compute them.

*/

#include<bits/stdc++.h>
using namespace std;


// Approach 1 
// Time - O(n*k) & space - O(1)

vector<int> maxSlidingWindow1(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> result;
    for(int i = 0; i < n-k+1; i++){
        int max = nums[i];
        for(int j = i; j < k+i; j++){
            if(nums[j] > max) max = nums[j];
        }
    result.push_back(max);
    }
    return result;
}

// Approach 2: Using double-ended queue
// Time - O(n) & Space - O(k)


// Note: Make sure max element is always present in the front of the queue
vector<int> maxSlidingWindow1(vector<int>& nums, int k){
    deque<int> q;
    vector<int> result;
    int n = nums.size();
    int i;
    //max among first k elements
    for(i = 0; i < k; i++){
        // while current value greater than previous value then delete that prev index(no use anymore)
        while(!q.empty() && nums[i] >= nums[q.front()]) 
            q.pop_back();
        q.push_back(i);
    }
    for(; i < n; i++){
        result.push_back(nums[q.front()]);
        while(!q.empty() && q.front() <= i-k)
            q.pop_front();
        while(!q.empty() && nums[i] >= nums[q.front()]) 
            q.pop_back();
        q.push_back(i);
    }
    result.push_back(nums[q.front()]);
    return result;
}