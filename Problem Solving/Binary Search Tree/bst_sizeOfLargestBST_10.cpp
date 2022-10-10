#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

// Problem => Given a binary tree , return the size of largest subtree of the binary tree which is a BST // Find out the largest BST within a Binary tree and return the size of the largest BST(i.e no. of nodes present in the BST)
// Approach => For every node, check if the currNode's subtree is a BST, its size(i.e no of nodes in a subtree), max elem, min elem // and if a subtree is a BST, then save its size -> iterate the whole Binary tree, find out BSTs and return the maxSize
// dry run

// a class with 4 properties which shall be returned by a node for that node's(currNode) respective subtree
class info {
    public:
       int maxi;
       int mini;
       bool isBST;
       int size;
};

info solve(TreeNode<int>* root, int &maxSize) {
    
    //base case
    if(root == NULL) {
         return {INT_MIN,INT_MAX, true, 0};   
    }
    
    info left = solve(root -> left, maxSize);           // recursive call for left subtree
    info right = solve(root -> right, maxSize);         // recursive call for right subtree
    
    info currNode;      // create a object(i.e node)
    
    currNode.size = left.size + right.size + 1;         // size of currNode = size of right & left subtree + 1(i.e size of currNode)
    currNode.maxi = max(root -> data,right.maxi);       // max value in the subtree of currNode -> max of (root node data & right's max bcz in a BST right subtree has all max values , so right subtree ka maximum value)
    currNode.mini = min(root -> data,left.mini);        // min value in the subtree of currNode -> min of (root node data & left's min bcz in a BST left subtree has all min values , so left subtree ka minimum value)
    
    //check if BST
    if(left.isBST && right.isBST && (root -> data > left.maxi && root -> data < right.mini )) {
        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }
    
    // if currNode's subtree is a BST, then calculate maxSize // calculate maxSize for every existing BST in the binary tree && return the max value
    if(currNode.isBST) {
        maxSize = max(maxSize, currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;            // max size of a BST in the binary tree
    info temp = solve(root,maxSize);        // func to find the maximum size, which shall return the 4 properties of class info
    return maxSize;
}


int main() {

return 0;
}