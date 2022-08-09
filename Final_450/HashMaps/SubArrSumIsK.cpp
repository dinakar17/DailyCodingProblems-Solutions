#include<bits/stdc++.h>
using namespace std;


int SubArrSumIsK(vector<int> nums, int k){
    int n = nums.size();
    unordered_map<int, int> m;
    // frequency of base prefix sum 0
    m[0] = 1;
    int ps = 0, ans =0;
    for(int i = 0; i < n; i++){
        ps += nums[i];
      // find for the occurrence of ps - k which implicitly mean that we're searching for
      // SubArray who sum is difference between ps -k and ps
      if(m.find(ps-k) != m.end()) ans += m[ps-k];
      m[ps]++;
    }
    return ans;
}