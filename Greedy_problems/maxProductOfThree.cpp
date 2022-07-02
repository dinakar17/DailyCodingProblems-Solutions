/*
Find the maximum product of three numbers in an array
*/

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    // The answer could be either the last three numbers or first two and last one of the array
    return max(arr[n-1]*arr[n-2]*arr[n-3], arr[n-1]*arr[0]*arr[1]);
}