#include <iostream>
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


// find height of a binary tree (i.e maximum no. of nodes from root node to leaf node)

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
    //if NULL, return 0
    if(node == NULL){
        return 0;
    }
    
    
    int left = height(node -> left);            //calculate height of left subtree(i.e left side) using recursion // dry run to understand better
    int right = height(node -> right);          //calculate height of right subtree(i.e right side) using recursion // dry run to understand better
    
    int ans = max(left,right) + 1;          // max of left and right + 1(i.e inclusion of root node) is the ans
    
    return ans;
    }
};

int main() {

return 0;
}