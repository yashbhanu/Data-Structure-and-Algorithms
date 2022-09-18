#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 


//Travere a binary tree 
//Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 1. Left boundary nodes 2. Leaf nodes 3. Reverse right boundary nodes
//Ref - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

//Approach => 1. traverse the left side nodes excluding the leaf node and push into array(i.e vector) // 2. traverse all leaf nodes in left and right subtree and push into array // 3. traverse all right side nodes excluding leaf nodes and push into array while returning from recursion tree/stack (i.e to push in reverse order) 


class Solution {
    
public:
    
    void leftTraversal(Node* root, vector <int> &ans) {
        
        //base case // if NULL or leaf node then return
        if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
            return ;
        }
        
        //push data of left side node into array
        ans.push_back(root -> data);
        
        //recursive call // if left exists then, keep on going left, else go on right
        if(root -> left) {
            leftTraversal(root -> left, ans);
        }
        else {
            leftTraversal(root -> right, ans);
        }
    }
    
    void traverseLeaf(Node* root, vector <int> &ans) {
        
        //base case
        if(root == NULL) return ;
        
        //check if leaf node, then push it into the array
        if(root -> left == NULL && root -> right == NULL) {
            ans.push_back(root -> data);
            return ;
        }
        
        //if not leaf node then keep traversing on the left & right subtree till you find leaf node
        traverseLeaf(root -> left , ans);
        traverseLeaf(root -> right, ans);
        
    }
    
    void rightTraversal(Node* root, vector <int> &ans) {
        //base case // if NULL or leaf node then return
        if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
            return ;
        }
        
        //recursive call // if right exists then, keep on going right, else go on left
        if(root -> right) {
            rightTraversal(root -> right, ans);
        }
        else {
            rightTraversal(root -> left, ans);
        }
        
        //wapis aate wakt print karna // print data while returning from recursive stack (to print in reverse order)
        ans.push_back(root -> data);
    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        ans.push_back(root -> data);        //push root node
        
        //left part print/store
        leftTraversal(root -> left, ans);
        
        //traverse leaf nodes
        //left subtree
        traverseLeaf(root -> left, ans);
        //right subtree
        traverseLeaf(root -> right, ans);
        
        //traverse right part
        rightTraversal(root -> right, ans);
        
        return ans;
    }
};

int main() {

return 0;
}