#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};


// Problem => Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -
// given a node, find the its kth ancestor(eg k = 2, go behind 2 times from the given node) // ref => https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1 

//Approach => keep traversing the tree left and right until you find the node, as soon as you find the node, return the node behind/upwards and keep decreementing k (i.e kth ancestor) till you reach k = 0 // as you reach k == 0 , kth ancestor is found, return that particular node(i.e root )


Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL) return NULL;
    
    // if node's data matches with the given node , i.e we found the node which was supposed to be found, hence return the node
    if(root->data == node) {
        return root;
    }
    
    //recursive function // traverse the tree left and right // which shall return the node which was supposed to be found
    Node* leftAns =  solve(root->left,k,node);
    Node* rightAns =  solve(root->right,k,node);
    
    //while returning // if leftAns (i.e node found) is not NULL and rightAns( NULL)
    if(leftAns != NULL && rightAns == NULL) {
        //then decreement k (i.e if k=2 , and the node is found, k-- = k = 1 (i.e we went one level behind, now we need to go one more level behind))
        k--;
        if(k <= 0) {
            
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;         // return the node behind, till k == 0
    }
    //while returning // if rightAns (i.e node found) is not NULL and leftAns( NULL)
    if(leftAns == NULL && rightAns != NULL) {
        //then decreement k (i.e if k=2 , and the node is found, k-- = k = 1 (i.e we went one level behind, now we need to go one more level behind))
        k--;
        // k == 0 , then kth ancestor is found, now we need to return the root node(i.e kth ancestor)
        if(k <= 0) {
            
            k = INT_MAX;        //answer lock
            return root;        //return the root node(i.e kth ancestor)
        }
        return rightAns;        // return the node behind, till k == 0
    }
    // Node not found (leftAns & rightAns both NULL, hence return NULL)
    return NULL;
}


// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root,k,node);         //recursive function which shall return the kth node // node = the node whose kth ancestor is supposed to be found 
    
    // check if the returned node is NULL (if yes, then -1) // another IMP check -> if the node == root node and k = 2 (i.e the node which is given doesnt have any kth ancestor) -> hence id the returned root node's data == given node, then -1
    if(ans == NULL || ans -> data == node) {
        return -1;
    }
    else {
        return ans->data;           // return kth ancestor node's data
    }
}


int main() {

return 0;
}