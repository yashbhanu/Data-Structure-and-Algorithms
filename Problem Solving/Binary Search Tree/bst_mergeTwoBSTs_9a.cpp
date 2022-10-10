#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

// Problem => merge two BSTs
//Approach 1 => you are given two root nodes of 2 BSTs respectively //step 1 : perform inorder traversal of both BSTs and save the sorted elems in 2 arrays 
//step 2 : now you have two sorted arrays(inorder traversal of both BSTs), now merge 2 sorted arrays 
//  step 3 : now you have one sorted array -> create a BST from that one sorted(inorderArrayToBST) array by finding the mid elem in array(create root node of mid elem)
//  and putting left part of array as leftsubtree && right part of array as rightsubtree on the root node(using recursion) 
// T.C && S.C -> O(m+n)

void inorder(TreeNode<int>* root, vector <int> &in) {
    //base case
    if(root == NULL) return ;
    //inorder traversal 
    inorder(root -> left, in);           // L
    in.push_back(root -> data);         //  N (save node data in array)
    inorder(root -> right, in);         //  R
}

vector<int> mergeArrays(vector <int> &a, vector <int> &b) {
    
    //create a new array (i.e mergedArray of a & b)
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;            //i = iterate a // j = iterate b // k = iterate ans 
    
    //loop over both a & b arrays till any one is completely iterated
    while(i < a.size() && j < b.size()) {
        //compare elem of a and b arrays // if a's elem is smaller, then store a's elem in ans, move forward ans & i 
        if(a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
        }
        // if a's elem is greater, then store b's elem in ans, move forward ans & j 
        else {
            ans[k++] = b[j];
            j++;
        }
    }
    // if j has iterated b completely, but some elem in a remain // then process remaining elems of a
    while(i < a.size()) {
         ans[k++] = a[i];
         i++;
    }
    // process remaining elems of b
    while(j < b.size()) {
         ans[k++] = b[j];
         j++;
    }
    return ans;
}
TreeNode<int>* inorderToBST(int s, int e,vector <int> &in) {
    
    //base case // start and end must not go past each other
    if(s > e) return NULL;
    
    int mid = (s+e)/2;      // find mid
    TreeNode<int>* root = new TreeNode<int>(in[mid]);           // create new node of mid elem
    root -> left = inorderToBST(s, mid-1, in);                  //  left part of mid as left subtree using recursion
    root -> right = inorderToBST(mid+1, e, in);                 // right part of mid as right subtree using recursion
    return root;
}


TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    //step 1 : store inorder
    vector <int> bst1;
    vector <int> bst2;
    //traverse tree to store all value of tree in a sorted order
    inorder(root1, bst1);
    inorder(root2, bst2);
    
    //step 2 : merge two sorted arrays
    vector<int> mergedArray = mergeArrays(bst1,bst2);
    
    //step 3 : use merged inorder array to build BST 
    int s = 0, e = mergedArray.size()-1;
    return inorderToBST(s,e,mergedArray);       //returns root node of merged BST
}

int main() {

return 0;
}