#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false

//Problem => Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
// given a node, check the sum of its left and right subtree is equal to the data of that node // check this for every node exclusing leaf nodes
// ref => https://practice.geeksforgeeks.org/problems/sum-tree/1

//Approach => create a pair(returns 2 vals) that returns true(i.e isSumTree) && sum
// if NULL create a pair(true, 0) and return // if leaf node create a pair(true, root node's data) and return // make recursive calls to right and left subtree to traverse tree and check for every node
//get isSumTree or not(true/false) // check condition that root node val == left & right subtree's sum // if everything is true, return true and sum, else return false

class Solution
{
    public:
    
    pair<bool,int> isSumTreeFast(Node* root) {
        
        // Base case // NULL (create pair (true, 0))
        if(root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        // leaf node (create pair (true,root node val))
        if(root -> left == NULL && root -> right == NULL) {
            pair<bool, int> p = make_pair(true, root -> data);
            return p;
        }
        
        //recursive calls // traverse the left and right subtrees and check for every node
        pair<bool, int> leftAns = isSumTreeFast(root -> left);
        pair<bool, int> rightAns = isSumTreeFast(root -> right);
        
        bool isleftSumTree = leftAns.first;          //extract isSumtree or not(true/false) 
        bool isrightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;           //extract left subtree and right Subtree's sum
        int rightSum = rightAns.second;
        
        bool condition = root->data == leftSum + rightSum;      //check condition that root node val == left & right subtree's sum
        
        pair<bool,int> ans;
        
        if(isleftSumTree && isrightSumTree && condition) {          // if everything is true, return true & sum of root & left & right subtree
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        }
        else {
            ans.first = false;
        }
        
        return ans;
        
    }
    
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};

int main() {

return 0;
}