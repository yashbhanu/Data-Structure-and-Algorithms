#include <iostream>
#include <vector>
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


//Problem => right view of binary tree (view diagram to understand better) ref => https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
//traverse the tree from its right view // some of the nodes may come in between the right view of the other nodes, hence they wont be visible and wont be printed

//Approach => // har level ki sabse pehli 1st node right to left traversal
//create levels to traverse through the levels(see img in lec 64) // we'll keep increasing levels to traverse by levels one by one
//dry run to understand better
 
 void solve(Node *root, vector<int> &ans, int level) {
     
     //base case
     if(root == NULL) return ;
     
     //we entered new level // if level is equal to arr/vector's size, then we entered a new level hence push_back the rightmost element in vector // for level 0 , vector.size == 0 , hence insert the root node // level 1, vector.size == 1 (we inserted a node earlier), hence now insert the the right node(i.e 1st node (R -> L) in level 1)
     if(level == ans.size()) {
         ans.push_back(root -> data);
     }
     
     //recursive calls // for traversal through the tree in left side and right side // as we its right view we'll traverse from right to left (hence right call is 1st and left is 2nd) // increase the levels to traverse levelwise
     solve(root -> right, ans, level+1);
     solve(root -> left, ans, level+1);
     
 }

//Function to return a list containing elements of right view of the binary tree.
vector<int> rightView(Node *root)
{
   vector<int> ans;        // to store elems of traversal
   solve(root, ans, 0);     
   return ans;
}

int main() {

return 0;
}