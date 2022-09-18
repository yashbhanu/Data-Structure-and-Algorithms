#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

//Problem => Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa
// ek tree di hai // usme ek node ke connected nodes ka data nhi le skte , but disconnected nodes ka data le skte hai, unhi disconnected nodes ke data ka maximum sum return krna hai
// ref => lec 65 => https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

// approach
// create a pair [a,b] where a = max sum by including nodes at current level (current node ko include krke uske sare unconnected nodes ka max sum), b = max sum by excluding nodes at current level(current node ko exclude krke uske sare unconnected nodes ka max sum)
// traverse through recursion left and right // for every node, create a pair res<a,b> // a = include the curr(root) node, so we cannot include connected nodes , hence left.second + right.second // b = exclude curr(root) node, hence can include the returned(descendant/connected nodes) data, we have 4 values returned in 2 pairs(left & right), include max(left.first,left.second) and max(right.first,right.second)
// return the pair as result // now return the max value in the pairs as ans

class Solution{
  public:
    
    pair<int,int> solve(Node *root) {
        
        //base case // if NULL create a pair<0,0> and return pair
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        //recursive calls // traversal towards left and right
        pair<int,int> left = solve(root -> left);
        pair<int,int> right = solve(root -> right);
        
        pair<int,int> res;      //create a pair res
        
        res.first = root -> data + left.second + right.second;          //max sum by including nodes at current level // include the curr(root) node, so we cannot include connected nodes , hence left.second + right.second
        res.second = max(left.first, left.second) + max(right.first, right.second);          //max sum by excluding nodes at current level // exclude curr(root) node, hence can include the returned(descendant/connected nodes) data, we have 4 values returned in 2 pairs(left & right), include max(left.first,left.second) and max(right.first,right.second)
        
        return res;
        
    }
  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);            // recursive function that shall return a pair
        return max(ans.first,ans.second);           // max value of 2 integers returned in pair
    }
};

int main() {

return 0;
}