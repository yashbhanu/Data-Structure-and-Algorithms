#include <iostream>
#include <vector>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Problem => Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K. A path may start from any node and end at any node in the downward direction.
// find no. of paths where the sum of the nodes in dat path is equal to K.
// ref => https://practice.geeksforgeeks.org/problems/k-sum-paths/1

//Approach // use recursion to traverse the tree left and right // keep pushig the nodes inside the vector // on every node run a for loop on the vector and calculate the sum && compare with k , if matches with k , then count++

class Solution{
public:
    
    void solve(Node *root,int k, int &count, vector<int> path) {
        
        //base case
        if(root == NULL) return ;
        
        path.push_back(root->data);     //push the node's data in array
        
        //recursive calls // traverse the tree left and right
        solve(root -> left,k,count,path);       //left
        solve(root -> right,k,count,path);      //right

        int size = path.size();     //get size of the vector
        int sum = 0;
        // for every node in the tree, calculate the sum of the nodes in that path(nodes stored in array/vector) and compare with K , if matches with k , count++
        for(int i = size-1; i >= 0; i--) {
            sum += path[i];
            if(sum == k) {
                count++;
            }
        }
        
    }    
  
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;      //count to store no. of paths where sum of nodes == k
        solve(root,k,count,path);
        return count;
    }
};

int main() {

return 0;
}