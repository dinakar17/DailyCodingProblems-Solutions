/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Given an array of numbers and a number k, 
determine if there are three entries in the array which add up to the specified number k. For example, given [20, 303, 3, 4, 25] and k = 49, return true as 20 + 4 + 25 = 49.
*/

#include<bits/stdc++.h>
using namespace std;


// Logic: Similar Logic applied to Two Sum problem

// Approach 1: Sorting

int ThreeSum(vector<int>& nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        int p1 = i + 1, p2 = n -1;
        while(p1 < p2){
            int sum = nums[i] + nums[p1] + nums[p2];
            if(sum == target) return 1;
            else if(sum > target) p2--;
            else p1++;
        }
    }
    return 0;
}

// Approach 2: Famous HashMap
int ThreeSum(vector<int>& nums, int target){
    int n = nums.size();
    

    for(int i = 0; i < n; i++){
        unordered_map<int, int> m;
        for(int j = 0; j < n; j++){
            if(i != j){
                int sum = nums[i] + nums[j];
                if(m.find(target - sum) != m.end()) {
                    cout << nums[i] << " " << nums[j] << " " << target-sum;
                    return 1;
                }  
                m[nums[i]] = i;          
            }
            m.clear();
        }
    }
    return 0;
}


int main(){
    vector<int> nums = { 1, 4, 45, 6, 10, 8};
    cout << ThreeSum(nums, 21);
}