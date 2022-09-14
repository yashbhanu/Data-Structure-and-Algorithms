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


//diameter of binary tree (i.e maximum distance(i.e max nodes) between two end nodes(i.e root & leaf nodes OR leaf nodes & leaf nodes))
//approach 1 => the distance(i.e path) exists in only right part of tree or only right part of tree OR combined in right and left tree
//hence, opt 1 => get max distance on complete left subtree, opt 2 => get max distance on complete right subtree, opt 3 => get max height of left subtree, right subtree and + 1 (add root node)
// ans  = max of (opt 1, opt 2, opt 3)

//T.C => O(n^2) . hence approach 2

class Solution {
  public:
    
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
    if(node == NULL){
        return 0;
    }
    
    int left = height(node -> left);
    int right = height(node -> right);
    
    int ans = max(left,right) + 1;
    
    return ans;
    }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        if(root == NULL) return 0;      //if root is NULL return 0
        
        //approach 1
        int opt1 = diameter(root -> left);          //find diameter(longest path) in left subtree (dry run the recursion to understand better)
        int opt2 = diameter(root -> right);         //find diameter(longest path) in right subtree (dry run the recursion to understand better)
        int opt3 = height(root -> left) + height(root -> right) + 1;            //find hright of left and right subtree and add 1 (i.e root node)
        
        int ans = max(opt1, max(opt2,opt3));            //ans shall be max of all three opts
        
        return ans;
        
    }
};


int main() {

return 0;
}