/*
Problem Description: Trapping Rain water
This problem was asked by Facebook.

You are given an array of non-negative integers that represents a two-dimensional elevation map 
where each element is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index,
 2 in the second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
*/

#include<bits/stdc++.h>
using namespace std;

// Logic: For every single element (height) find its left maximum and right maximum and calculate min(left max, right max) - curr_ele
// Imagine practically to comprehend the above logic
int trap(vector<int> height){
    int n = height.size();
    int trapped_water = 0;
    for(int i = 0; i < n; i++){
        int left_max = 0;
        for(int j = i; j >= 0; j--){
            left_max = max(left_max, height[j]);
        }
        int right_max = 0;
        for(int j = i; j < n; j++){
            right_max = max(right_max, height[j]);
        }
        trapped_water += min(left_max, right_max) - height[i];
    }
    return trapped_water;
}

// Optimization: Instead of finding left_max every single time for each element store it in an array and do the same for right_max as well.

int trap_time_optimized(vector<int> height){
    int n = height.size();
    int trapped_water = 0;
    int left[n];
    int left_max = 0;
    for(int i = 0; i < n; i++){
        left_max = max(left_max, height[i]);
        left[i] = left_max;
    }
    int right[n];
    int right_max = 0;
    for(int i = n-1; i >= 0; i--){
        right_max = max(right_max, height[i]);
        right[i] = right_max;
    }

    for(int i = 0; i < n; i++){
        trapped_water += min(left[i], right[i]) - height[i];
    }
    return trapped_water;
}

// Space optimization: Instead of storing each and every left max and right max during each iteration, observe that in the end we're calculating
// min(left_max, right_max) =>Now, It is possible to find the same minimum of max's directly using some "if else" conditions
int trap_space_optimized(vector<int> height){
    int n = height.size();
    int trapped_water = 0;
    int left_max = 0, right_max = 0;
    int left = 0, right = n-1;
    while(left <= right){
        if(height[left] < height[right]){
            if(height[left] > left_max){
                // => min(left_max, right_max) = left_max since height[r](right_max) > height[l] > left_max
                left_max = height[left];
            }
            // we found the left_max to our current element which is lower than the right_max
            else trapped_water += left_max - height[left];
            left++;
        }
        else{
            if(height[right] > right_max){
                // => min(left_max, right_max) = right_max since height[l](left_max) > height[r] > right_max
                right_max = height[right];
            }
            // we found the right_max to our current element which is lower than the left_max
            else trapped_water += right_max - height[right];
            right--;
        }
    }
    return trapped_water;
}

