#include<bits/stdc++.h>
using namespace std;


int maxSubArraySum(vector<int>& nums){
    int n = nums.size();
    int msf = 0,  ans = INT_MIN;
    for(int i = 0; i < n; i++){
        msf = max(msf + nums[i], nums[i]);
        ans = max(msf, ans);
    }
    return ans;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArraySum(nums);
    return 0;
}