// // Given the root of a binary tree, return the preorder traversal of its nodes' values.

// // What is preorder traversal -- In preorder traversal, we start with root node, then we traverse through the entire left subtree and 
// // after finishing that we come back to the root node and then traverse the entire right subtree


// Definition for a binary tree Node

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

Node* buildTree(vector<int> tree){
    if(tree.empty() || tree[0] == -1) return NULL;

    int n = tree.size();
    Node* root = new Node(tree[0]);
    queue<Node*> q;

    q.push(root);

    int i = 1;
    while(!q.empty() && i < n){
        Node* curr = q.front();
        q.pop();

        //left child
        if(i < n && tree[i] != -1){
            curr->left = new Node(tree[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < n && tree[i] != -1) {
            curr->right = new Node(tree[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;

}

void preorder(Node* root, vector<int>& ans);
vector<int> preorderTraversal(Node* root);

int main(void){

    vector<int> arr = {1, -1, 2, 3}; // [1,null,2,3]

    Node* root = buildTree(arr);

    vector<int> ans = preorderTraversal(root);

    for (int x : ans) {
        cout << x << " ";
    }

    return EXIT_SUCCESS;
}


void preorder(Node* root, vector<int>& ans) {
    if (root == nullptr) return;

    ans.push_back(root->val);   // Root
    preorder(root->left, ans);  // Left
    preorder(root->right, ans); // Right
}

vector<int> preorderTraversal(Node* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

