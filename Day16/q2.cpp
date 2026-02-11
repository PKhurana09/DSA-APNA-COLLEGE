// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for a binary tree node.

struct Node {
    int val;
    Node* left;
    Node* right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node* left, Node* right) : val(x), left(left), right(right) {}
};

Node* buildTree(vector<int> tree){
    if(tree.empty() || tree[0] == NULL) return NULL;
    int n = tree.size();

    Node* root = new Node(tree[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < n){
        Node* curr = root;

        q.pop();

        if(i < n && tree[i] != NULL){
            curr->left = new Node(tree[i]);
            q.push(curr->left);
        }
        i++;

        if(i < n && tree[i] != NULL){
            curr->right = new Node(tree[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}


vector<vector<int>> levelOrder(Node* root);


int main(void){

    return EXIT_SUCCESS;
}
