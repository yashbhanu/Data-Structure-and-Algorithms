#include <iostream>
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

// Problem => Given a binary search tree and an integer 'K'. task is to find out the 'k-th' smallest element
// Approach -> as inorder traversal of a BST is always in a sorted manner , traverse using inorder and as u visit a node for printing, increase the count and as u react kth count(ans found), return that node

int solve(BinaryTreeNode* root, int &i, int k) {
    
    //base case
    if(root == NULL)
        return -1;
    
    //L  // left traversal
    int left = solve(root->left,i,k);
    if(left != -1) {
        return left;
    }
    
    //N
    i++;        //increase count
    //check if i(count) has reached kth count // eg k = 3, while you reach 3rd node in inorder traversal(i.e 3rd smallest node), i==k, then return that node
    if(i == k) {
        return root -> data;        // ans found // return kth element's node data
    }
    
    //R     //left traversal
    return solve(root -> right,i,k);
    
}

int kthSmallest(BinaryTreeNode* root, int k) {
    int i = 0;      //count
    int ans = solve(root, i, k);        
    return ans;
}

int main() {

return 0;
}