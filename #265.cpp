/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Atlassian.

MegaCorp wants to give bonuses to its employees based on how many lines of codes they have written.
They would like to give the smallest positive amount to each worker consistent with the constraint that
if a developer has written more lines of code than their neighbor, they should receive more money.

Given an array representing a line of seats of employees at MegaCorp, determine how much each one should get paid.

For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1].
*/
#include <bits/stdc++.h>
using namespace std;

// Distribute Candies problem
// Ref: https://youtu.be/bC7o8P_Ste4

vector<int> DistributePayments(vector<int> &seats)
{
    int n = seats.size();
    // Note: we use vector instead of map because does not allow duplicate keys
    vector<pair<int, int>> dict;
    for (int i = 0; i < n; i++)
    {
        dict.push_back({seats[i], i});
    }
    sort(dict.begin(), dict.end());

    vector<int> payments(n, 1);
    for (int j = 0; j < n; j++)
    {
        pair<int, int> p = dict[j];
        int i = p.second; // index
        if (i > 0 && seats[i] > seats[i - 1])
            payments[i] = max(payments[i], payments[i - 1] + 1);
        if (i < n - 1 && seats[i] > seats[i + 1])
            payments[i] = max(payments[i], payments[i + 1] + 1);
    }
    return payments;
}

int main()
{
    vector<int> seats = {10, 40, 200, 1000, 60, 30};
    int n = seats.size();
    vector<int> ans = DistributePayments(seats);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}