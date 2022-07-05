/*
Problem Description:
This problem was asked by Spotify.

You are the technical director of WSPT radio, serving listeners nationwide. For simplicity's sake we can consider each listener to live along a horizontal line stretching from 0 (west) to 1000 (east).

Given a list of N listeners, and a list of M radio towers, each placed at various locations along this line, determine what the minimum broadcast range would have to be in order for each listener's home to be covered.

For example, suppose listeners = [1, 5, 11, 20], and towers = [4, 8, 15]. In this case the minimum range would be 5, since that would be required for the tower at position 15 to reach the listener at position 20.

*/

// In simpler words, find the maximum of minimum distances between the "listener" and towers

#include <bits/stdc++.h>
using namespace std;

int minBroadCastRange(vector<int> listeners, vector<int> towers)
{
    int n = listeners.size();
    int m = towers.size();
    int minBroadCastRange = 0;
    for (int l = 0; l < n; l++)
    {
        int broadcast_range = INT_MAX;
        for (int t = 0; t < m; t++)
        {
            broadcast_range = min(broadcast_range, abs(listeners[l] - towers[t]));
        }
        minBroadCastRange = max(broadcast_range, minBroadCastRange);
    }
    return minBroadCastRange;
}

// Optimization: Since both the arrays are sorted, in order to find the min distance between the listener and tower,
// we can now compare the listener with only the towers that are present to its left and right instead with all the towers.
// (comparisons are optimized here...)

int MinBroadCastRange_optimized(vector<int> listeners, vector<int> towers)
{
    int n = listeners.size();
    int m = towers.size();
    int l = 0, t = 0;
    int minBroadCastRange = 0;
    int leftTower = INT_MIN, rightTower = towers[0];
    while (l < n)
    {
        if (listeners[l] < rightTower)
        {
            int leftRange = listeners[l] - leftTower;
            int rightRange = rightTower - listeners[l];
            int broadcast_range = min(leftRange, rightRange); // this gives the best minimum instead of using for-loop
            minBroadCastRange = max(minBroadCastRange, broadcast_range);
            l++;
        }
        else
        {
            leftTower = towers[t];
            if (t < m - 1)
            {

                rightTower = towers[++t];
            }
            else if (t == m - 1)
            {

                rightTower = INT_MAX;
            }
        }
    }
    return minBroadCastRange;
}

int main()
{
    vector<int> listeners{1, 5, 11, 20};
    // vector<int> listeners{12, 13, 11, 80};
    vector<int> towers{4, 8, 15};
    // vector<int> towers{4, 6, 15, 60};

    cout << MinBroadCastRange_optimized(listeners, towers);
    return 0;
}
