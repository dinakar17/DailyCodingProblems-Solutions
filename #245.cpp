/*
This problem was asked by Yelp.

You are given an array of integers, where each element represents the maximum number of steps that can be jumped going forward from that element. Write a function to return the minimum number of jumps you must take in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2, as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.
*/

#include<bits/stdc++.h>
using namespace std;

// Logic: At first glance, one could think of finding max element among the steps you can take i.e.,
// In example [6, 2, 4, 0, 5, 1, 1, 4, 2, 9] if you're at index "0" then 5 is max among [2, 4, 0, 5, 1, 1]("6"(arr[0]) steps)
// That is incorrect! It fails for many test cases for example ["""9, 8, 2, 2, 0, 2, 2, 0, 4,""" 1, 5, 7, 9, 6, 6, 0, 6, 6, 0, 5]
// If the above same logic is applied we will choose element "8" first but correct option is to choose element "4" among 9 steps we take.

// That draws to the conclusion that instead of finding maxElement among the steps. In simple words, 
// we need to find the max index we can get to among those steps we can take.
// It is required to find max of (i + arr[i]) among the steps => max(element(8) + it'sIndex(1), element(4) + it'sIndex(8)) => it's best to go to index 12 rather that 9
int minJumps(int arr[], int n){
     
        int i = 0; 
        int count = 0;
        while(i < n){
            int steps = arr[i];
            if(steps == 0) return -1;
            // The below two lines is implementation to find the max element among "arr[i]" steps
            // int max_step = arr[i+1];
            // int max_step_idx = i+1;

            // The below two lines is implementation to find the max of among (i + arr[i]) 
            int maxReach = i + arr[i];
            int maxReachIdx = i;
            for(int j = i + 1; j < steps + 1 + i; j++){
                // if(max_step < arr[j] || (arr[j] + j >= n-1)){
                //     max_step = arr[j];
                //     max_step_idx = j;
                // }
                if(j == n-1) return count+1;
                // Here we're finding maximum index we can reach (this should make sense) from the element arr[j]
                if(maxReach < j + arr[j]){
                    maxReach = j + arr[j];
                    maxReachIdx = j;
                }
                
            }
            i = maxReachIdx;
            count++;
        }
        return count;

}

int main(){
    int arr[] = {9,8,2,2,0,2,2,0,4,1,5,7,9,6,6,0,6,5,0,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minJumps(arr, n);
    return 0;
}