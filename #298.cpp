/*

Problem Description:
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

A girl is walking along an apple orchard with a bag in each hand. She likes to pick apples from each tree as she goes along, but is meticulous about not putting different kinds of apples in the same bag.

Given an input describing the types of apples she will pass on her path, in order, determine the length of the longest portion of her path that consists of just two types of apple trees.

For example, given the input [2, 1, 2, 3, 3, 1, 3, 5], the longest portion will involve types 1 and 3, with a length of four.

*/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int longestPath(vector<int> apples)
{
    int n = apples.size();
    unordered_set<int> s;
    int i = 0;
    int max_path = 0, local_max_path = 0;
    while (i < n)
    {
        s.insert(apples[i]);
        if (s.size() > 2)
        {
            s.clear();
            max_path = max(local_max_path, max_path);
            local_max_path = 0;
            i--;
            while (apples[i] == apples[i - 1] && i >= 0)
                i--;
        }
        else
        {
            local_max_path++;
            i++;
        }
    }
    return max(max_path, local_max_path);
}

int main()
{
    // vector<int> apples{1, 2, 2, 2, 2, 3, 3, 1, 3, 1, 5};
    // vector<int> apples{1, 1, 2, 3, 4, 4, 3, 4, 6};
    vector<int> apples{2, 1, 2, 3, 3, 1, 3, 5};
    cout << longestPath(apples);
    return 0;
}