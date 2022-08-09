#include<bits/stdc++.h>
using namespace std;



// Logic: Keep the frequency count of remainder of prefix sum

int subArrSumDivByK(vector<int> nums, int k){
    int n = nums.size();
    unordered_map<int, int> m;

    // frequency of zero sum
    m[0] = 1;
    // prefix sum
    int ps = 0, ans = 0;
    for(int i = 0; i < n; i++){
        ps += nums[i];
        // calculate reminder of the prefix sum and search if that remainder ocurred already.
        int x = (ps % k + k) % k;
        ps += m[x]; // default value of undefined key is 0 in unordered_map
        m[x]++;
    }
    return ans;
}