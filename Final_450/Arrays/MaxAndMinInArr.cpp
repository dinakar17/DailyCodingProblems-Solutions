#include<bits/stdc++.h>
using namespace std;


int maxElement(vector<int>& nums){
    int n = nums.size();
    // initial assumption
    int max_val = nums[0];
    for(int i = 0; i < n; i++){
        max_val = max(max_val, nums[i]);
    }
    return max_val;
}

int minElement(vector<int>& nums){
    int n = nums.size();
    // initial assumption
    int min_val = nums[0];
    for(int i = 1; i < n; i++){
        min_val = min(min_val, nums[i]);
    }
    return min_val;
}

