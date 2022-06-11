/*
Problem Description:
    This problem was asked by Glassdoor.

An imminent hurricane threatens the coastal town of Codeville. 
If at most two people can fit in a rescue boat, and the maximum weight limit for a given boat is k,
 determine how many boats will be needed to save everyone.

For example, given a population with weights [100, 200, 150, 80] and a boat limit of 200,
 the smallest number of boats required will be three.

*/
#include<bits/stdc++.h>
using namespace std;

// Solution - refer to https://leetcode.com/problems/boats-to-save-people/solution/
int numRescueBoats(vector<int>& people, int limit){
    int n = people.size();
    int i = 0, j = n-1;
    int boatCount = 0;
    while(i <= j){
        boatCount++;
        if(people[i] + people[j] <= limit) i++;
        j--;
    }
    return boatCount;
}