#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& left, vector<int>& right, vector<int>& nums){
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;
    while(i < nL && j < nR){
        if(left[i] < right[j]) nums[k++] = left[i++];
        else nums[k++] = right[j++];
    }
    //Note: It is k++ not ++k
    while(i < nL) nums[k++] = left[i++];
    while(j < nR) nums[k++] = right[j++];
}


void mergeSort(vector<int>& nums){
    int n = nums.size();
    if(n <= 1) return;
    int mid = n/2;
    vector<int> left(mid, 0);
    vector<int> right(n - mid, 0);
    for(int i = 0; i < mid; i++) left[i] = nums[i];
    for(int i = mid; i < n; i++) right[i-mid] = nums[i];
    mergeSort(left);
    mergeSort(right);
    // This logic is super important
    // Here left -> leftNode and right -> rightNode and nums -> parentNode
    merge(left, right, nums);
}

int main(){
    vector<int> nums = {5, 6, 8, 1, 8, 2, 3};
    mergeSort(nums);
    for(int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    return 0;
}

// Applications: #165, #44