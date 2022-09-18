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


//Problem => left view of binary tree (view diagram to understand better) ref => https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
//traverse the tree from its left view // some of the nodes may come in between the left view of the other nodes, hence the wont be visible and wont be printed

//Approach => // har level ki sabse pehle  1st node left to right traversal
//create levels to traverse through the levels(see img in lec 64) // we'll keep increasing levels to traverse by levels one by one
//dry run to understand better
 
 void solve(Node *root, vector<int> &ans, int level) {
     
     //base case
     if(root == NULL) return ;
     
     //we entered new level // if level is equal to arr/vector's size, then we entered a new level hence push_back the leftmost element in vector // for level 0 , vector.size == 0 , hence insert the root node // level 1, vector.size == 1 (we inserted a node earlier), hence now insert the the left node(i.e 1st node (L -> R) in level 1)
     if(level == ans.size()) {
         ans.push_back(root -> data);
     }
     
     //recursive calls // for traversal through the tree in left side and right side // as we its left view we'll traverse from left to right (hence left call is 1st and right is 2nd) // increase the levels to traverse levelwise
     solve(root -> left, ans, level+1);
     solve(root -> right, ans, level+1);
     
 }

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> ans;        // to store elems of traversal
   solve(root, ans, 0);     
   return ans;
}



int main() {

return 0;
}