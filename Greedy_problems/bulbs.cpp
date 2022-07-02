/*
N light bulbs are connected by a wire.

Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.

Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.

You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.
*/

#include<bits/stdc++.h>
using namespace std;

// Two set of Logics to approach the answer
int bulbs(vector<int> &A){
    int n = A.size();
    int switches = 0;
    for(int i = 0; i < n; i++){
        // 1. If number of switches are even, then all the bulbs revert back to their initial state,
        // hence there is not need to change the bulb value and meanwhile odd number of switches,
        // causes the bulbs to change their value 
        if(switches % 2 == 0) A[i] = A[i];
        else A[i] = !A[i];

        // 2. This logic is straight forward from the question itself. If the bulb value is 1 do nothing.
        // else you have to change the value of the bulb to 1 (i.e., you have to switch on the bulb)
        if(A[i] % 2 == 1) continue;
        else switches += 1;
    }
    return switches;
}