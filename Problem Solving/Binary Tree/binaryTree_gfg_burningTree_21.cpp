#include <iostream>
#include <bits/stdc++.h>
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

// Problem => Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
// You would be given a binary Tree and a target node in that binary tree , you need to start burning tree from that target node // the target node would burn its left and right child and its parent
/*
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
*/
// If leaf with the value 
// 8 is set on fire. 
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree. // Output = 7

// Approach => step 1 : create NodeToParentMapping (a map where a node is mapped to its corresponding parent node) // step 2 : find target node // step 3 : burn tree in min time
// use level order traversal , hence queue

class Solution {
  public:
    
    // creates nodeToParentMapping and finds target node and returns
    Node* createParentMapping(Node* root, int target, map<Node* , Node* > &nodeToParent) {
        Node* res = NULL;       // result node (i.e target node which shall be returned)
        
        //traverse using level order traversal // hence queue
        queue<Node *> q;
        q.push(root);           //push the root node in the queue
        nodeToParent[root] = NULL;          // match the root node to NULL as root node has no parent
        
        //iterate the queue // traversal 
        while(!q.empty()) {
            
            Node* front = q.front();            // get the front node
            q.pop();
            
            //find target node // if front node's data is equal to target then assign front node to res node(i.e target node found)
            if(front -> data == target) {
                res = front;
            }
            
            // if front ka left exists, then // map front node ka left (i.e child of front node) to front node(i.e parent node)
            if(front -> left) {
                nodeToParent[front->left] = front;
                q.push(front -> left);          //push left node in queue // traversal
            }
            
            // if front ka right exists, then // map front node ka right (i.e child of front node) to front node(i.e parent node)
            if(front -> right) {
                nodeToParent[front->right] = front;
                q.push(front -> right);         //push right node in queue // traversal
            }
        }
        return res;         //return target Node        
    }
    
    int burnTree(Node* root , map<Node* , Node* > &nodeToParent) {
        
        map<Node*, bool> visited;           //check if visited(i.e burned) // is visited then burnt
        queue<Node*> q;                     // level order traversal (hence queue)
        
        q.push(root);
        visited[root] = true;       //burnt (i.e visited == true)
        
        int ans = 0;        // min time to burn (i.e count)
        
        //traversal
        while(!q.empty()) {
            
            bool flag = 0;      //flag to check if new elem is added to queue
            int size = q.size();
            
            //iterate the queue
            for(int i = 0; i < size; i++) {
                //process neighbouring nodes
                Node* front = q.front();
                q.pop();
                
                //burn left subtree/nodes
                if(front -> left && !visited[front -> left]) {
                    flag = 1;           // flag = 1 means new node has been added into queue
                    q.push(front -> left);              // push the left node  // we are pushing the nodes into the queue so that we can traverse throught the tree & check if burnt or not
                    visited[front -> left] = 1;         // front node ka left is now visisted
                }
                
                // burn right subtree/nodes
                if(front -> right && !visited[front -> right]) {
                    flag = 1;
                    q.push(front -> right);
                    visited[front -> right] = 1;
                }
                
                //burn parent nodes
                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = 1;
                    q.push(nodeToParent[front]);            // push the parent node
                    visited[nodeToParent[front]] = 1;       // front(root) node ka parent is now visited 
                }
                
            }
            // flag is true , then some node has been pushed into queue && the current(i.e root/front) node's left & right & parent are burnt => so count(i.e ans)++
            if(flag == 1) {
                ans++;
            }
        }
        return ans;
        
    }
    
  
    int minTime(Node* root, int target) 
    {
        // algo
        // step 1 : create NodeToParentMapping (a map where a node is mapped to its corresponding parent node)
        // step 2 : find target node
        // step 3 : burn tree in min time
        
        map<Node* , Node* > nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);         // pass root , target and nodeToParent map in func , which shall return the target node
        
        int ans = burnTree(targetNode, nodeToParent);           // pass targetNode and nodeToParent in func, which shall return the ans(i.e min time to burn tree)
        
        return ans;
    }
};

int main() {

return 0;
}