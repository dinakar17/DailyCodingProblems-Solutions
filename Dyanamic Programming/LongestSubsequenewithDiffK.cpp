#include<bits/stdc++.h>
using namespace std;


// longest subsequence whose difference is less than or equal to k
int longestSubSeq(vector<int>& nums, int k){
    int n = nums.size();

    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(abs(nums[i] - nums[j]) <= k) dp[i] = max(dp[i], dp[j] + 1); 
        }
    }
    for(auto i : dp) cout << i << " ";
    cout << endl;
    return *max_element(dp.begin(), dp.end());
}


int main(){
    vector<int> nums = {0, 1, 2, 3};
    cout << longestSubSeq(nums, 3); // 4
}