/*
Good morning! Here's your coding interview problem for today.

This problem was asked by WhatsApp.

Given an array of integers out of order, determine the bounds of the smallest window 
that must be sorted in order for the entire array to be sorted. 

For example, given [3, 7, 5, 6, 9], you should return (1, 3).
*/

#include<bits/stdc++.h>
using namespace std;

pair<int, int> BoundsOfSmallestWindow(vector<int>& nums){
    int n = nums.size();
    pair<int, int> p(INT_MAX, INT_MIN);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(nums[i] > nums[j]){
                swap(nums[i], nums[j]);
                p.first = min(p.first, i);
                p.second = max(p.second, j);
            }
        }
    }
    return p;
}

int main(){
    vector<int> nums = {3, 7, 5, 6, 4, 9, 11, 12, 13};
    int n = nums.size();
    pair<int, int> ans = BoundsOfSmallestWindow(nums);
    cout << ans.first << " " << ans.second << " ";
    return 0;
}