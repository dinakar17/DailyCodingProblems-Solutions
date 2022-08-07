#include<bits/stdc++.h>
using namespace std;


void moveNegative(vector<int>& nums){
    int n = nums.size();
    int neg = 0;
    int i  = 0;
    while(i < n){
        if(nums[i] < 0) swap(nums[neg++], nums[i]);
        i++;
    }
}

void moveNegativeEnd(vector<int>& nums){
    int n = nums.size();
    int p = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] > 0) swap(nums[p++], nums[i]);
    }
}


int main(){
    vector<int> nums = {-1, 2, -13, -4, 5};
    moveNegativeEnd(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}