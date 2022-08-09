#include<bits/stdc++.h>
using namespace std;


int findLongestConseqSubseq(vector<int>& nums){
    int n = nums.size();
    set<int> s;
    for(int i = 0; i < n; i++) s.insert(nums[i]);

    int ans = 0;

    for(int i = 0; i < n; i++){
        int cnt = 0;
        if(s.find(nums[i] - 1) == s.end()){
            int temp = nums[i];
            while(s.find(temp) != s.end()){
                temp += 1;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    return ans;
}