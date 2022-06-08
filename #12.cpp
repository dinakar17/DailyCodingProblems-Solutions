/*
Problem Description:

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. 
Given N, write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

Extension:

What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? 
 For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

// Logic - Just a simple mathematical function where x(n) = x(n-1) + x(n-2) (present value depends on past two subsequent values)

#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n){
    if(n == 1 || n == 2) return n;
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    //Note: i < n+1
    for(int i = 3; i < n+1; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}


int main(){
    cout << climbStairs(4);
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n)
