/* This problem was asked by Google.

Given an array of integers, return a new array where each element in the new array is the number of smaller elements to the right of that element in the original input array.

For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

There is 1 smaller element to the right of 3
There is 1 smaller element to the right of 4
There are 2 smaller elements to the right of 9
There is 1 smaller element to the right of 6
There are no smaller elements to the right of 1
*/

// Naive approach is using bubble Sort

#include<bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int>>& left, vector<pair<int, int>>& right, vector<pair<int, int>>& nums, vector<int>& count){
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;
    while(i < nL && j < nR){
        // This is where the most important logic is going on...
        // To understand the below logic work with {3, 4, 9, 6, 1} and also better understanding of binary tree and
        // recursion is required
        if(left[i].first <= right[j].first) nums[k++] = right[j++];
        else{
            count[left[i].second]  += (nR - j);
            nums[k++] = left[i++];
        }
        // Alternative and Intuitive logic 
        /* If left arr element is smaller than right arr element then we have no inversion */
        // if(left[i].first <= right[j].first) nums[k++] = left[i++];
        /* If left arr element is greater than right arr element then we have inversion */
        // else{
        //     int temp = i;
        // Note that if left = [3, 4] and right = [1, 6, 9] then since 3 > 1 => count[left[temp].second] should be incremented
        // for all the elements that are present in the left arr 
        //     while(temp < nL) count[left[temp].second]  += 1, temp++;
        //     nums[k++] = right[j++];
        // }
    }
    while(i < nL) nums[k++] = left[i++];
    while(j < nR) nums[k++] = right[j++];
}

void mergeSort(vector<pair<int, int>>& nums, vector<int>& count){
    int n = nums.size();
    if(n <= 1) return;
    int mid = n / 2;
    vector<pair<int, int>> left;
    vector<pair<int, int>> right;
    for(int i = 0; i < mid; i++) left.push_back(nums[i]);
    for(int i = mid; i < n; i++) right.push_back(nums[i]);
    
    mergeSort(left, count);
    mergeSort(right, count);
    merge(left, right, nums, count);   

}

int main(){
    // vector<int> nums = {9, 6, 1};
    vector<int> arr = {3, 4, 9, 6, 1};
    int n = arr.size();
    vector<pair<int, int>> nums;
    for(int i = 0; i < n; i++) nums.push_back({arr[i], i});
    
    vector<int> count(n, 0);
    mergeSort(nums, count);
    for(int i = 0; i < count.size(); i++) cout << count[i] << " ";
    return 0;
}