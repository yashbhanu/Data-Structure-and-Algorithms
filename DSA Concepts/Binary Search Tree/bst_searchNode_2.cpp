#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// search for a node in binary search tree

class BinaryTreeNode {
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


bool searchInBST(BinaryTreeNode *root, int x) {
     BinaryTreeNode *temp = root;
    
    while(temp != NULL) {
        if(temp->data == x) {
            return true;
        }
        
        if(temp->data > x) {
      // no. is greater than x, hence we need smaller vals , hence left part
            temp = temp -> left;
        }
        else {
            // no. is smaller than x,hence we need larger vals, hence left part
            temp = temp -> right;
        }
    }
    return false;
}


int main() {

return 0;
}