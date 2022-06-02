/*
Problem Description:
Good morning! Here's your coding interview problem for today.

This problem was asked by Netflix.

Given an array of integers, determine whether it contains a Pythagorean triplet.
Recall that a Pythogorean triplet (a, b, c) is defined by the equation a2+ b2= c2.
*/
#include <bits/stdc++.h>
using namespace std;

bool checkTriplet(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] * arr[i];
        s.insert(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s.find(arr[i] + arr[j]) != s.end())
                return true;
        }
    }
    return false;
}

/* Space complexity - O(n)
Time complexity - O(n**2) */