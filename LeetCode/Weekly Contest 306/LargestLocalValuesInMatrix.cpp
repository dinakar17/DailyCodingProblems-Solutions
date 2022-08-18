/*
You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> res(n - 2, vector<int>(n - 2));

    for (int i = 0; i < n - 2; i++)
    {
        int max_val = 0;
        for (int j = 0; j < n - 2; j++)
        {
            for (int k = j; k < j + 3; k++)
                max_val = max({max_val, grid[i][k], grid[i + 1][k], grid[i + 2][k]});
            res[i][j] = max_val;
            max_val = 0;
        }
    }
    return res;
}