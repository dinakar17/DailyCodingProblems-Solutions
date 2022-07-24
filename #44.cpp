/*
This problem was asked by Google.

We can determine how "out of order" an array A is by counting the number of inversions it has. Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
*/

// This problem is an application of mergeSort and also #44 problem

// Naive approach

#include<bits/stdc++.h>
using namespace std;

int countInversions(vector<int>& nums){
    int n = nums.size();
    int inv_count = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < i; j++){
            if(nums[i] > nums[j]) inv_count += 1;
        }
    }
    return inv_count;
}
// Time Complexity - O(n^2)
// Space Complexity - O(1)

// Optimization using MergeSort
int merge(vector<int>& left, vector<int>& right, vector<int>& nums){
    int nL = left.size();
    int nR = right.size();
    int inv_count = 0;
    int i = 0, j = 0, k = 0;
    while(i < nL && j < nR){
        if(left[i] <= right[j]) nums[k++] = left[i++];
        else{
            // ex: left = [3, 4] & right - [1, 6, 9] since 3 > 1 also means that 4 > 1 so inv_count = (2 - i)
            inv_count += (nL - i); 
            nums[k++] = right[j++];
        }
    }
    while(i < nL) nums[k++] = left[i++];
    while(j < nR) nums[k++] = right[j++];

    // Note: This is the count assigned to the parent node
    return inv_count;
}

int mergeSort(vector<int>& nums){
    int n = nums.size();
    // Base case
    if(n <= 1) return 0; // no inversions for a single element
    int cnt1 = 0; // for left node
    int cnt2 = 0; // for right node 
    int cnt3 = 0; // for parent node
    int mid = n/2;
    vector<int>left;
    vector<int> right;
    for(int i = 0; i < mid; i++) left.push_back(nums[i]);
    for(int i = mid; i < n; i++) right.push_back(nums[i]);

    cnt1 += mergeSort(left);
    cnt2 += mergeSort(right);
    // The moment our compiler reaches this line to evaluate we should understand that we've got hold of parent node
    // which means we can also have access to its left and right nodes too.
    cnt3 += merge(left, right, nums);

    return (cnt1 + cnt2 + cnt3);  
}

int main(){
    // vector<int> nums = {2, 4, 1, 3, 5}; // 3
    vector<int> nums = {5, 4, 3, 2, 1}; // 10
    cout << mergeSort(nums);
    return 0;
}