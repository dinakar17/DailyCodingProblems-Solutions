/*
Problem Description:  Good morning! Here's your coding interview problem for today.

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

*/

#include <bits/stdc++.h>
using namespace std;

// Note  - Remember counting number of zeros
void productExceptSelf(int arr[], int n)
{
    // count no of zeros and calculate remaining no's product
    int count = 0;
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count++;
        else
            prod *= arr[i];
    }

    // Write conditions depending on number of zeros present in array
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            arr[i] = prod / arr[i];
        else if (count == 1)
        {
            if (arr[i] == 0)
                arr[i] = prod;
            else
                arr[i] = 0;
        }
        else
            arr[i] = 0;
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {-1, 1, 0, -3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);
    productExceptSelf(arr, n);
    print(arr, n);
}