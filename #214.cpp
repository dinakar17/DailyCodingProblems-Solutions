/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Given an integer n, return the length of the longest consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.
*/

#include<bits/stdc++.h>
using namespace std;

// Logic: For example take n = 14. Binary representation 1110
/*
   01110
   11100
  -------
   01100  => count = 1
*/

//Note: And operator is gives 1 if and only if both the bits are 1 

int maxConsecutiveOnes(int n){
    int count = 0;
    while(n != 0){
        n = n & (n << 1);
        count++;
    }
    return count;
}

int main(){
    cout << maxConsecutiveOnes(14);
    return 0;
}