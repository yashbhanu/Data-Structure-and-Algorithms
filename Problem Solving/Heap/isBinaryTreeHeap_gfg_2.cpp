#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// Problem => check if the given Binary tree is a Heap

//Approach => an heap is a CBT(Complete Binary Tree(i.e left to right)) & followes Heap Property (Max or Min Heap)
// 1. Create 2 functions which checks if a BT is CBT & follows Heap property | If both are true(i.e both functions return true then its Heap else its not)
// 2. CBT func -> if we have a BT with suppose 6 nodes | In a heap , if every node is given an index then the index of the last node will always be equal to no. of nodes (i.e index of last node(i.e 6) == no. of nodes(i.e 6)) | But in a BT, if we assign indexes to each node, then (index of last node(i.e 6) != no. of nodes(i.e 6)) bcz nodes & indexes are not placed synchronoulsy (left to right), indexes will also consider NULL pointers........
//......hence, index of particular nodes would be greater than no. of nodes | hence check if index >= no. of nodes, if true that means its not a BT | use recursion and traverse through all nodes and check them
// 3. isMaxOrdrder -> if heap property is followed(max heap) -> a.leaf node -> no children hence no comparsion of data , return true | b. only left exists(only right cannot exist bcz L->R), root node's data greater than left child, then return true | c. both node exists , use recursion to traverse through left & right subtree && root node's data greater tthan both left and right child,return True(max heap exists)


class Solution {
  public:
    
    int countNodes(struct Node* root) {
        if(root == NULL) {
            return 0;
        }
        // '1' for current root node + recursion to calculate nodes in left subtree + recursion to calculate nodes in right subtree 
        int count = 1 + countNodes(root -> left) + countNodes(root -> right);
        return count;
    }
    
    //check if CBT
    bool isCBT(struct Node* root, int index, int totalNodes) {
        
        if(root == NULL)
            return true;
            
        // if CBT , then last node's index == no. of nodes // check if CBT or not ,if index value exceeds total no. of nodes
        if(index >= totalNodes) {
            return false;
        }
        else {
            // check CBT for left & right subtree & find left & right children indexes by formulae
            bool left = isCBT(root->left, 2*index+1, totalNodes);
            bool right = isCBT(root->right, 2*index+2,totalNodes);
            // if left and right subtree both are true then return true
            return (left && right);
        }
    }
    
    bool isMaxOrder(struct Node* root) {
        //leaf node // if both child are NULL, then leaf node (i.e return true bcz no value comparsion bw children, hence heap property is followed)
        if(root -> left == NULL && root -> right == NULL) {
            return true;
        }
        
        //if only left node exists // then check root node's data greater than left child's data -> True then it follows heap property
        if(root -> right == NULL) {
            if(root -> data > root -> left -> data) {
                return true;
            }
        }
        //both node exists
        else {
            // check heap property for both left & right subtree by using recursion for traversal
            bool left = isMaxOrder(root -> left);
            bool right = isMaxOrder(root -> right);
            
            // if left & right subtree follows heap property && root's data greater than both left & right child -> return true as it follows heap property
            return (left && right && root->data > root->left->data && root->data > root->right->data);
        }
        
    }
    
  
    bool isHeap(struct Node* tree) {
        int index = 0;
        
        // count total no. of nodes
        int totalNodes = countNodes(tree);
        
        // check if CBT & max heap property | both true then its a heap
        if(isCBT(tree, index, totalNodes) && isMaxOrder(tree)) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

return 0;
}