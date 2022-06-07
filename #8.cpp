/*
Problem Description:
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Google.

    A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

    Given the root to a binary tree, count the number of unival subtrees.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Tip: Try out the problem with a test case on a paper to understand the algorithm

bool univalTrees(Node *root, int &count)
{
    // This root node points to node *after* a leaf node or *after* node with one of its children NULL
    if (root == NULL)
        return true;
    /*
    Note: Similar to preorder traversal
    Possibilities
    1) left = True and right = True => For Node that is either a leaf Node
        or Node (and is a unival tree) with one of its children NULL
    2) left = False (left Node is not a unival tree) and right = True (right Node is a unival tree)
     || left = True and right = False
    3) left = False (left is not a unival tree) and right = False (right Node is not a unival tree)
    */
    bool left = univalTrees(root->left, count);
    bool right = univalTrees(root->right, count);

    if (left == false || right == false)
        return false;
    // Even though if left = True and right = True we have to check if the Node's one of the children is NULL
    if (root->left && root->data != root->left->data)
        return false;
    if (root->right && root->data != root->right->data)
        return false;

    // If all above conditions are passed then the node and everything underneath it indicates a unival tree
    count++;
    return true;
}

int CountUnivalTrees(Node *root)
{
    int count = 0;
    univalTrees(root, count);
    return count;
}