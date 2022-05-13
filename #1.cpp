/*

Problem Description: Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

*/

#include<bits/stdc++.h>
using namespace std;


// Brute force approach
bool twoSum1(int arr[], int n, int k){
     for(int i = 0; i < n; i++){
         for(int j = i + 1; j < n; j++){
             if(arr[i] + arr[j] == k) return true;
         }
     }
     return false;
}

// Input Array Sorted

bool twoSum2(int arr[], int n, int k){
    sort(arr, arr+n);
    int i = 0, j = n-1;
    while(i < j){
      int sum = arr[i] + arr[j];
      if(sum == k) return true;
      else if(sum > k) j--;
      else i++;
    }
    return false;
}

// Using HashMap

bool twoSum3(int arr[], int n, int k){
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        int pair = k - arr[i];
        if(m.find(pair) != m.end()) return true;
        m[arr[i]] = i;
    }
    return false;
}

int main(){
    int arr[] = {10, 5, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 17;
    cout << twoSum1(arr, n, k) << endl;
    cout << twoSum2(arr, n, k) << endl;
    cout << twoSum3(arr, n, k) << endl;
    return 0;
}