#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

// Problem => Given an array which represents a PREORDER traversal of a BST // all vals are stored in array such that if we would have traversed the tree in preorder way
// Given that array of preorder traversal create a BST such that if we traverse that tree in preorder, the same array would be created // BST from preorder traversed array // 

// Approach => create a range (-inifinity, inifinity) -> initally // traverse the array -> create a root node // and for the next nodes check if the node is in that range, if yes then create node or return NULL
// dry run to understand better

BinaryTreeNode<int>* solve(vector<int> &preorder,int mini, int maxi, int &i) {
    //base case
    // if array is completely iterated, return NULL
    if(i >= preorder.size()) return NULL;
    
    // if any elem/node->data is not in the specific range of min/max, then return NULL
    if(preorder[i] < mini || preorder[i] > maxi) return NULL;
    
    //create node // && i++ , move forward in array
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);     //N
    
    //recursive calls
    root -> left = solve(preorder,mini,root -> data ,i);            // L // create nodes to left // range between (-infinite, root -> data) bcz leftsubtree of root has smaller values, hence limit the max val
    root -> right = solve(preorder,root -> data,maxi ,i);           // R // create nodes to right // range between (root -> data, infinite) bcz rightsubtree of root has larger values, hence limit the min val
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    //range (-inifinity, inifinity) initally
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;          // index to traverse array
    
    return solve(preorder,mini,maxi ,i);        //recursive function // passed preorder array, range & index to it // which shall return the root node of the preordered created BST
}

int main() {

return 0;
}