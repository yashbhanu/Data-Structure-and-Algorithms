#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

//Problem => Diagonal traversal of a tree // view diagram  to understand better// ref => https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

//Approach => create a a queue(to store the nodes) => push the root node , pass the root node, queue and ans vector to a recursive function // store the left node of root node (as we have to go left to right (diagonally), store left, so for next level, we'll start from left to right) and then keep traversing right 

void solve(Node *root,queue<Node*> &q, vector<int> &ans) {
    
    //base case // if NULL return
    if(root == NULL) {
        return;
    }
    
    //push the node's data in ans vector
    ans.push_back(root -> data);
    
    // if left exists, push into queue // as we are traversing left to right for every level, save the left node of the next level, and keep traversing right // for the next level, we'll start from left(from the node saved in queue) and keep traversing right  
    if(root -> left) {
        q.push(root -> left);
    }
    
    // recursive call //keep traversing right 
    solve(root -> right, q, ans);
    
}


vector<int> diagonal(Node *root)
{
   
   
   vector<int> ans;
   if(root == NULL) return ans;     //if root is NULL, return   
   
   
   queue<Node* > q;         // queue to store the nodes
   q.push(root);           //push the root node in the queue
   
   //loop till queue is empty
   while(!q.empty()) {
       
       // pass the root node, queue and ans vector to a recursive function
       solve(q.front(), q, ans);
       q.pop();         //pop from the queue
       
   }
   
   return ans;
   
}

int main() {

return 0;
}