#include<bits/stdc++.h>
using namespace std;


// iterative
void reverse(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n/2; i++){
        swap(nums[i], nums[n-i-1]);
    }
}


void reverseArr(vector<int>& nums, int leftIdx, int rightIdx){
    // base case
    if(leftIdx >= rightIdx) return;
    swap(nums[leftIdx], nums[rightIdx]); // This is the important line that recursive function does
    reverseArr(nums, leftIdx+1, rightIdx-1);
}


int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    reverseArr(nums, 0, nums.size()-1);
    for(int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
}