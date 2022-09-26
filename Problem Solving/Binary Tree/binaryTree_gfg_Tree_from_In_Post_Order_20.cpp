#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;

   Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

// Construct Tree from Inorder & Postorder
// Given 2 Arrays of Inorder and Postorder traversal. Construct a tree // Eg. inorder[] = {4 8 2 5 1 6 3 7} Postorder[] = {8 4 5 2 6 7 3 1} // root node shall be postorder's last element(i.e 1) bcz postorder is LRN (Last node is root node)
// now find '1' in inorder array // 1 ke left m {4 8 2 5} h toh binary Tree main '1' (i.e root node) ke left pt. krega {4 8 2 5} ko // && // inorder array m '1' ke right m {6 3 7} hai ,
//  toh '1' (i.e root node) ke right main aayega [6,3,7] // call the recursive function for right{6,3,7} && left{4 8 2 5} // root node find karo inorder array m (i.e 3) as we are traversing back post-- // find '3' in preorder array // 3 ke left m '6' h toh binary Tree main '3' (i.e node) ke left pt. krega 6 ko 
// && // inorder array m '3' ke right m {7} hai , toh '6' (i.e node) ke right main aayega {7} // continue till you build a tree && return the root node

// ref => https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

// Approach => Algo. 0. base case 1. take index element as root node 2. find root node's position in inorder array 3. recursive function calls for left and right


int findPosition(int in[], int element, int n) {
        
    for(int i = 0; i < n; i++) {
        if(in[i] == element) {
                return i;
            }
        }
    return -1;
}
    
    
    Node* solve(int in[], int post[],int &index, int inorderStart, int inorderEnd, int n) {
        
        //base case // if index which is iterating the postorder array iterates the whole array OR || when 2 pointers start & end go pass each other
        if(index < 0 || inorderStart > inorderEnd) {
            return NULL;
        }
        
        //get element in post order array (i.e root node)//get element and decreement the index
        int element = post[index--];
        //create node from the element fetched from post order arr
        Node* root = new Node(element);
        //find element in inorder //  get position
        int position = findPosition(in, element, n);
        
        //recursive calls  // right and left // left (inorder array, pre arr, inorder index, inorderStart, left side of element found in inorder arr(i.e pos-1), n) // right (inorder array, pre arr, inorder index, left side of element found in inorder arr(i.e pos+1) , inorderEnd, n)
        // Incase of postOrder build the right subtree first then left subtree
        root -> right =  solve(in, post, index, position+1, inorderEnd, n);
        root -> left =  solve(in, post, index, inorderStart, position-1, n);
        
        return root;
        
    }

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    int postOrderIndex = n-1; int inOrderIndex = 0;         // as its postOrder(root node as last node (LRN)) we'll traverse from back (hence n-1)
    // pass all arrays and start & end indexes in func
    Node* ans = solve(in, post, postOrderIndex, inOrderIndex, n-1, n);
    return ans;
}



int main() {

return 0;
}