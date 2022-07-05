/*
This problem was asked by Google.

In linear algebra, a Toeplitz matrix is one in which the elements on any given diagonal from top left to bottom right are identical.

Here is an example:

1 2 3 4 8
5 1 2 3 4
4 5 1 2 3
7 4 5 1 2
Write a program to determine whether a given input is a Toeplitz matrix.
*/

// Given a matrix, we generally traverse through it through columns first and then rows
// i.e., (0,1) -> (0, 1) -> (0, 2) -> (0, 3) and (1, 0) -> (1, 1) -> (1, 2) -> (1, 3)

// Logic:
// During that traversal we can access "diagonal element" of "current element" i.e., for (1, 1) -> (0, 0)
// for (1, 2) -> (0, 1), (1, 3) -> (0, 2) and so on...

#include<bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> matrix){
    int rows = matrix.size();
    int columns = matrix[0].size();
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < columns; c++){
            if(r > 0 && c > 0 && matrix[r-1][c-1] != matrix[r][c]) return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> matrix{{1, 2, 3, 4, 8}, {5, 1, 2, 3, 4}, {4, 5, 1, 2, 3}, {7, 4, 5, 1, 2}};
    cout << isToeplitz(matrix);
    return 0;
}