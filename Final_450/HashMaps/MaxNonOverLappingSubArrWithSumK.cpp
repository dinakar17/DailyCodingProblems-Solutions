#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


int NonOverlappingSubArr(vector<int> nums, int k){
    int n = nums.size();
    unordered_set<int> s;
    int cnt = 0;
    s.insert(0);
    int ps = 0;
    for(int i = 0; i < n; i++){
        ps += nums[i];
        if(s.find(ps-k) != s.end()) cnt++;
        s.insert(ps);
    }
    return cnt;
}