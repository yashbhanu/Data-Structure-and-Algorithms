#include <iostream>
#include <bits/stdc++.h>
using namespace std;


    class BinaryTreeNode 
    {
    public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
    };

//check if the given BST is a valid BST
// Approach -> for every node check if the value is in given range

bool isBST(BinaryTreeNode *root, int min, int max) {
    
    //base case
    if(root == NULL)
            return true;
    
    // if root node is in the range of (INT_MIN && INT_MAX i.e denotes a range of (-infinite, +infinite)), then proceed
    if(root -> data >= min && root -> data <= max) {
        bool left = isBST(root -> left, min, root -> data);         //check the left subtree i.e all the nodes in the left subtree lie in range (INT_MIN, root's data) i.e -infinite to root node's data (bcz values in left subtree are always smaller than root node)       
        bool right = isBST(root -> right, root -> data, max);       //check the right subtree i.e all the nodes in the right subtree lie in range (root's data, INT_MAX) i.e root node's data to infinite (bcz values in right subtree are always greater than root node)       
        return left && right;                   // return true or false
    }
    else {
        return false;
    }
    
}

bool validateBST(BinaryTreeNode *root) {
     return isBST(root, INT_MIN, INT_MAX);          //pass root, INT_MIN, INT_MAX (INT_MAX && INT_MIN denotes a range of (-infinite, +infinite))
}

int main() {

return 0;
}