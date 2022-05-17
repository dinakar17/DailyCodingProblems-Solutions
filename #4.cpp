/*
Problem Description:
Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words,
find the lowest positive integer that does not exist in the array.

The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force approach

int firstMissingPosI(int arr[], int n)
{
    int ref = 1;

    // Maximizing Searches for the ref value
    for (int i = 0; i < n; i++)
    {
        // Search for the ref value if found increment it
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == ref)
                ref += 1;
        }
    }
    return ref;
}

// Sorting arrpoach

int firstMissingPos2(int arr[], int n)
{
    sort(arr, arr + n);
    int ref = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            if (arr[i] == ref)
                ref += 1;
            // Handling Duplicates
            else if (arr[i] == ref - 1)
                continue;
            else
                return ref;
        }
    }
    return ref;
}

// Hashing - Sorting done using extra space in O(n)

int firstMissingPos3(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            s.insert(arr[i]);
    }
    int ref = 1;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        if ((*i) == 1)
            ref += 1;
        else if ((*i) == ref - 1)
            continue;
        else
            return ref;
    }
    return ref;
}

// Solution we're looking for: O(n) linear time and O(1) extra space

// int segregate(int arr[], int n)
// {
//     int j = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] <= 0)
//         {
//             swap(arr[i], arr[j]);
//             j++;
//         }
//     }
//     return j;
// }
// int firstMissingPos4(int arr[], int n)
// {
//     int i = segregate(arr, n);
//     for(; i < n; i++){
//         int abs_val = abs(arr[i]);
//         int idx = abs_val - 1;
//         if(idx < n && idx > 0) arr[idx] = -arr[idx];
//     } 

//     for(int i = 0; i < n; i++){
//         if(arr[i] > 0) return i + 1;
//     }
//     return n + 1;
// }

int main()
{
    int arr[] = {1, 1, 0, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << firstMissingPos3(arr, n) << endl;
}