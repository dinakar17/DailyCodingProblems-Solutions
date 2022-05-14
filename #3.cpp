/*

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string,
and deserialize(s), which deserializes the string back into the tree.

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

// Function to create node in a binary tree
Node* createNode(int data){
    Node* node = new Node();
    node -> data = data;
    node -> left = node -> right = NULL;
    return node;
}

// Function to insert a node in a given binary tree;

void insert(Node* *root, int data)
{
    if (!(*root))
    {
        *root = createNode(data);
        return;
    }
    else
    {
        queue<Node *> q;
        q.push(*root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            else
            {
                temp->left = createNode(data);
                return;
            }
            if (temp->right)
                q.push(temp->right);
            else
            {
                temp->right = createNode(data);
                return;
            }
        }
    }
}

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

string serialize(Node* root){
    queue<Node* > q;
    q.push(root);
    string ans = "";
    while(q.empty() == false){
        Node* temp = q.front();
        q.pop();
        ans += to_string(temp -> data);
        if(temp -> left) q.push(temp -> left);
        if(temp -> right) q.push(temp -> right);
    }
    return ans;
}

Node* deserialize(string str){
    Node* root = NULL;
    int n = str.length();
    for(int i = 0; i < n; i++){
        insert(&root, (str[i] - '0'));
    }
    return root;
}

int main()
{
    Node *root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    preorder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    cout << serialize(root) << endl;
   
    Node* decoded_tree = deserialize(serialize(root));
    levelOrder(decoded_tree);
    return 0;
}
