#include <iostream>
#include <vector>
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

// Problem => Convert a binary search tree into a Linked list // Flatten BST to sorted linked list
// Approach => 1.Traverse the tree using inorder and save the all elems in a array(Sorted manner bcz inorder traversal of a binary search tree is always sorted)
// 2.iterate the array and create a node for each element pointing to each other


void inorder(TreeNode<int>* root, vector <int> &in) {
    //base case
    if(root == NULL) return ;
    //inorder traversal 
    inorder(root -> left, in);           // L
    in.push_back(root -> data);         //  N (save node data in array)
    inorder(root -> right, in);         //  R
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector <int> inorderVal;
    //traverse tree to store all value of tree in a sorted order
    inorder(root, inorderVal);
    int n = inorderVal.size();
    
    //create the root node of LL
    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);
    //pointer poiting towards the new root node
    TreeNode<int>* curr = newRoot;
    
    // loop over array and create a new node for LL till end of array
    for(int i = 1; i < n; i++) {
        
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);         //new node
        curr -> left = NULL;            // new node's left pointing to NULL
        curr -> right = temp;           // curr node's(prev node) right pointing to next node(i.e temp)
        curr = temp;                    // move curr forward
    }
    // last node // last node's left and right both pointing NULL
    curr -> left = NULL;
    curr -> right = NULL;
    
    return newRoot;
    
}


int main() {

return 0;
}