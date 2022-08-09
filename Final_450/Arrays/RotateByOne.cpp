#include<bits/stdc++.h>
using namespace std;


void rotateByOne(vector<int>& nums){
    int temp = nums[0];
    for(int i = 0; i < nums.size()-1; i++){
        nums[i] = nums[i+1];
    }
    nums[nums.size()-1] = temp;
}


int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    rotateByOne(nums);
    for(int i : nums) cout << i << " ";
}