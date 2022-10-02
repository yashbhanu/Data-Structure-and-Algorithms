#include <iostream>
using namespace std;

class TreeNode {
        public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

// Problem => Givven a binary tree with two nodes P & Q // Find the lowest common ancestor of both the nodes
// Approach
// Condition 1 => Both Nodes P & Q are in right subtree(i.e both P and Q are greater than root) => traverse the right tree via recursion and find LCA
// Condition 2 => Both Nodes P & Q are in left subtree(i.e both P and Q are smaller than root) => traverse the left tree via recursion and find LCA
// Condition 3 => One node (e.g P) is in left subtree and another node (e.g Q) is in right subtree (i.e root-> data > P->data && root -> data > Q -> data) => simply return root node as both P & Q LCA will always be root node


TreeNode* LCAinaBST(TreeNode* root, TreeNode* P, TreeNode* Q)
{
	// base case
    if(root == NULL) return NULL;
    
    //recursive calls
    if(root-> data < P->data && root -> data < Q -> data) {
        return LCAinaBST(root->right, P, Q);
    }
    if(root-> data > P->data && root -> data > Q -> data) {
        return LCAinaBST(root->left, P, Q);
    }
    
    return root;
}

int main() {

return 0;
}