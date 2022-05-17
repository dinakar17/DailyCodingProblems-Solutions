/*

Problem Description: 

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

*/

#include<bits/stdc++.h>
using namespace std;

// Logic - Track two sums (1 - sum that *includes* current ele) & (2 - sum that *excludes* current ele)
// Similar to DP (dynamic programming problem) 
int maxNonAdjSum(vector<int>& nums){
    int n = nums.size();
    // Declare variables that stores the above two different sums
    int excl = 0, incl = nums[0]; // min size of nums = 0;

    /* Should start from i = 1 */
    for(int i = 1; i < n; i++){
        // int excl_new = incl; 
        int excl_new = max(incl, excl);  // !update from above old statement
        // update incl sum
        incl = excl + nums[i]; // think about this line for a moment or two 
        // update excl sum
        // excl = incl;
        excl = excl_new; // !update from above old statement
    }

    // pick max sum from either of them and return the max sum
    return max(excl, incl);
}

int main(){
    vector<int> nums{5, 1, 1, 5};
    cout << maxNonAdjSum(nums);
    return 0;
}