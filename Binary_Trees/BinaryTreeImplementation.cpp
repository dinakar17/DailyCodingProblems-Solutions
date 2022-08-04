#include<bits/stdc++.h>
using namespace std;

// binary tree implementation
class Node{
    public:
    int val;
    Node* left;
    Node* right;
};

Node* createNode(int val){
    Node* node = new Node();
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

// iterative
void insert(Node** root, int val){
    if(!(*root)){
        *root = createNode(val);
        return;
    }

    queue<Node*> q;
    q.push(*root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp -> left) q.push(temp->left);
        else {
            temp -> left = createNode(val);
            return;
        }
        if(temp -> right) q.push(temp -> right);
        else{
            temp -> right = createNode(val);
            return;
        }
    }
}



void preorder(Node* root){
    if(!root) return;
    cout << root -> val << " ";
    preorder(root -> left);
    preorder(root -> right);
}

int main(){
    Node* root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    preorder(root);
}






