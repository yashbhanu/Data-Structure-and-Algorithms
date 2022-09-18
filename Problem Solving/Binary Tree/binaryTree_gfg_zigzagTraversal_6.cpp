#include <iostream>
#include <vector>
#include <queue>
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

// Problem => ZigZag Traversal => Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.
//Ref = https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

//Approach => we'll use level order traversal to traverse and just change the order of insertion (i.e leftToRight && rightToLeft) // whenever there is level order traversal, use queue
// we must return an array(i.e vector) as an answer // so push all the zigzag traversed nodes into the array(i.e vector)

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector <int> result;
    	
    	if(root == NULL) return result;     //if NULL, return
    	
    	queue<Node* > q;
    	q.push(root);           //push the root node in the queue
    	
    	bool leftToRight = true;        // create a flag (i.e leftToRight) // first we'll insert leftToRight , then rightToLeft
    	
        //loop till queue is empty
    	while(!q.empty()) {
    	     
    	     int size = q.size();       // get size of queue
    	     
    	     vector<int> tempAns(size);         // create a vector(of queue's size) to store elems that will come from the queue
    	     
    	     //level process // process every level
    	     for(int i = 0; i < size; i++) {
    	         Node* frontNode = q.front();       //get the front node in the queue and pop it
    	         q.pop();
    	         
                 // now we need to insert the elem obtained from queue in a vector //either leftToRight OR rightToLeft // if leftToRight is true, then insert normally (i.e leftToRight => (i)), if false then rightToLeft(i.e reverse => (size - i - 1) using formula) 
    	         int index = leftToRight ? i : size - i - 1;
    	         tempAns[index] = frontNode -> data;
    	         
                 // if the node's left & right child exists, then push into the queue
    	         if(frontNode -> left)
    	            q.push(frontNode -> left);
    	            
    	         if(frontNode -> right)
    	            q.push(frontNode -> right);
    	            
    	     }
    	     
             //change the direction to insert
    	     leftToRight = !leftToRight;
    	     
             //loop over tempAns vector and insert all elems into result vector(i.e array) // for every level, tempAns vector shall insert all elems into result vector
    	     for(auto i : tempAns) {
    	         result.push_back(i);
    	     }
    	}
    	
    	return result;
    }
};

int main() {

return 0;
}