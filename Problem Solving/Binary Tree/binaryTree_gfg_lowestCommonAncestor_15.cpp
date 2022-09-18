#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Problem => The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.
// lowest common ancestor (i.e sabse PEHELA ANCESTOR of 2 given nodes(n1,n2)) // ref diagram => https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

//dry run to understand better

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        //base case
        if(root == NULL) {
            return NULL;
        }
        
        //base case // if node's data matches with either n1 or n2 , then return that node
        if(root -> data == n1 || root -> data == n2) {
            return root;        
        }
        
        //recursive calls // traverse the tree left & right // the recursive func shall return a node as leftAns & rightAns
        Node* leftAns = lca(root->left,n1,n2);
        Node* rightAns = lca(root->right,n1,n2);
        
        // for a node if the returned nodes in leftAns and rightAns are not NULL,then that node is the lca(i.e ans), hence  return it
        if(leftAns != NULL && rightAns != NULL) {
            return root;        //lca
        }
        
        // if leftAns is Not null, and rightAns is NULL, then return leftAns ,, and vice versa
        else if(leftAns != NULL && rightAns == NULL) {
            return leftAns;
        }
        
        else if(leftAns == NULL && rightAns != NULL) {
            return rightAns;
        }
        else {      //both leftAns & rightAns are  NULL
            return NULL;
        }
        
    }
};

int main() {

return 0;
}