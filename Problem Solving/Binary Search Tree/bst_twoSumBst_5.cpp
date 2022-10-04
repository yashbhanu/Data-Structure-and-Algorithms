#include <iostream>
#include <vector>
using namespace std;

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

// Problem => Given a BST,and a target , find out the two sum. Check in the whole tree that if the sum of two elem's(node's) data is equal to target
// Approach => Traverse the tree using inorder and save the all elems in a array(Sorted manner bcz inorder traversal of a binary search tree is always sorted)
// traverse the array using 2 pointer approach and check if pair exists

void inorder(BinaryTreeNode* root, vector <int> &in) {
    //base case
    if(root == NULL) return ;
    //inorder traversal 
    inorder(root -> left, in);      // L
    in.push_back(root -> data);     // N (save node data in array)
    inorder(root -> right, in);     // R
}

bool twoSumInBST(BinaryTreeNode* root, int target) {
    vector <int> inorderVal;
    //traverse tree to store all value of tree in a sorted order
    inorder(root, inorderVal);
    
    //use two pointer approach to check if pair exists
    int i = 0; int j = inorderVal.size() - 1;       // j at last elem in array
    
    while(i < j) {
        int sum = inorderVal[i] + inorderVal[j];        //calculate sum
        if(sum == target)           // check if sum is equal to target, if yes return true(i.e pair exists)
            return true;
        // if calculated sum is greater than target, i.e target is smaller , we have to reduce the sum -> hence j-- (as arrays is sorted)
        else if(sum > target)
            j--;
        // if calculated sum is lesser than target, i.e target is greater , we have to increase the sum -> hence i++ (as arrays is sorted)
        else
            i++;
    }
    return false;       // if pair doesn't exist, return false
}

int main() {

return 0;
}