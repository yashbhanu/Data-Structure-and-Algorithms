#include <iostream>
#include <vector>
using namespace std;

template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

//convert a normal BST into a balanced BST // balanced BST = a BST, in which height of two subtrees of every node differs than one // matlab height/level sabki same ho , bas 1 level aage peeche ho skta hai

//Approach => perform inorder traversal of tree and store values in vector(array) // use binary search method on array // find out mid and create a new node for it -> left part of the mid will become left subtree -> right part of the mid will become right subtree
// such a way divide array into half from the mid && one half on left && one half on right // and balanced BST will be created


void inorder(TreeNode<int>* root, vector <int> &in) {
    //base case
    if(root == NULL) return ;
    
    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

TreeNode<int>* inorderToBST(int s, int e,vector <int> &in) {
    
    //base case // start and end must not go past each other
    if(s > e) return NULL;
    
    int mid = (s+e)/2;      // find mid
    TreeNode<int>* root = new TreeNode<int>(in[mid]);           // create new node of mid elem
    root -> left = inorderToBST(s, mid-1, in);                  //  left part of mid as left subtree using recursion
    root -> right = inorderToBST(mid+1, e, in);                 // right part of mid as right subtree using recursion
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector <int> inorderVal;
    //inorder traverse tree to store all value of tree in a sorted order
    inorder(root, inorderVal);
    
    //convert normal BST to balance // pass start(0), end index of arr(inorderVal.size()-1), and vector to func // which shall return root node of balanced tree
    return inorderToBST(0, inorderVal.size()-1, inorderVal);
    
}


int main() {

return 0;
}