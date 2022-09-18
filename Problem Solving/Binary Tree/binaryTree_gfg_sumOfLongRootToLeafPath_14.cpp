#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};


// Problem => Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered
// Sum of all nodes on the longest path (i.e root node se leaf node tak longest path find karo and uss longest path ka sum of all nodes) // agar sab paths ki length same toh, maximum value of sum of all nodes
// Ref => https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

// Approach => traverse the tree by recursion and keep increasing the levels and for every node and level , add the sum(i.e data of that node) and in the end find out the max value of the sum of all nodes of a particular path
// dry run to understand better

class Solution
{
    
    
public:
    
    void solve(Node *root, int sum, int &maxSum, int len, int &maxLen) {
        
        //base case
        if(root == NULL) {
            
            // if root is NULL, then we are either on 1st node i.e null, or on the leaf node => if we are on leaf node, we must have increased the value of length, hence check if len(i.e current length) > maxLen => if yes, update the maxLen and maxSum
            if(len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            // if we have path with equal no. of nodes (i.e len == maxLen), then only update maxSum (i.e maximum of current sum of maxSum)
            else if(len == maxLen) {
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        // add the node's value to the sum
        sum = sum + root -> data;
        
        //recursive calls  // towards right & left // keep increasing len (to traverse the tree)
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);
        
    }

    
    int sumOfLongRootToLeafPath(Node *root)
    {           
        int len = 0;        //  to store current length
        int maxLen = 0;     // to store maximum length
        
        int sum = 0;        //  to store current sum
        int maxSum = INT_MIN;            // to store maximum sum
        
        solve(root, sum, maxSum, len, maxLen);              //recursive function
        
        return maxSum;          //return maxSum as ans(i.e maximum sum of longest path)
    }
};

int main() {

return 0;
}