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

// Construct Tree from Inorder & Preorder
// Given 2 Arrays of Inorder and preorder traversal. Construct a tree // Eg. inorder[] = {1 6 8 7} preorder[] = {1 6 7 8} // root node shall be preorder's 1st element(i.e 1) bcz inorder is NLR (1st node is root node)
// now find '1' in inorder array // 1 ke left m kuch nhi h toh binary Tree main '1' (i.e root node) ke left pt. krega NULL ko // && // inorder array m '1' ke right m {6,8,7} hai ,
//  toh '1' (i.e root node) ke right main aayega [6,8,7] // call the recursive function for {6,8,7} // root node find karo inorder array m (i.e 6) // find '6' in preorder array // 6 ke left m kuch nhi h toh binary Tree main '6' (i.e node) ke left pt. krega NULL ko 
// && // inorder array m '6' ke right m {8,7} hai , toh '6' (i.e node) ke right main aayega {8,7} // continue till you build a tree && return the root node

// ref => https://practice.geeksforgeeks.org/problems/construct-tree-1/1

// Approach => Algo. 0. base case 1. take index element as root node 2. find root node's position in inorder array 3. recursive function calls for left and right


class Solution{
    public:
    int findPosition(int in[], int element, int n) {
        
        for(int i = 0; i < n; i++) {
            if(in[i] == element) {
                return i;
            }
        }
        return -1;
    }
    
    
    Node* solve(int in[], int pre[],int &index, int inorderStart, int inorderEnd, int n) {
        
        //base case // if index which is iterating the preorder array iterates the whole array OR || when 2 pointers start & end go pass each other
        if(index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        
        // get the element in pre order array (i.e root node)//get element and increement the index
        int element = pre[index++];
        //create node from the element fetched from pre order arr
        Node* root = new Node(element);
        //find element in inorder // get position
        int position = findPosition(in, element, n);
        
        //recursive calls // left and right // left (inorder array, pre arr, inorder index, inorderStart, left side of element found in inorder arr(i.e pos-1), n) // right (inorder array, pre arr, inorder index, left side of element found in inorder arr(i.e pos+1) , inorderEnd, n)
        root -> left =  solve(in, pre, index, inorderStart, position-1, n);
        root -> right =  solve(in, pre, index, position+1, inorderEnd, n);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0; int inOrderIndex = 0; 
        // pass all arrays and start & end indexes in func
        Node* ans = solve(in, pre, preOrderIndex, inOrderIndex, n-1, n);
        return ans;
    }
};

int main() {

return 0;
}