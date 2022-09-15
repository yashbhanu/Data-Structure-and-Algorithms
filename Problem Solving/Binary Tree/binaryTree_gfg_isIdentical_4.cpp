#include <iostream>
using namespace std;

//Problem => Given two binary trees, the task is to find if both of them are identical or not. 

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

//Approach => comapare both the trees (if both are NULL nodes) // use recursive call to traverse the tree and compare the nodes // comapare the values stored in the nodes
//if everything is true, then return true else return false
   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //base case
        if(r1 == NULL && r2 == NULL) return true;       //if both nodes are NULL, return true
        
        if(r1 == NULL && r2 != NULL) return false;      // one is NULL, the other is NON NULL, return false
        
        if(r1 != NULL && r2 == NULL) return false;
        
        //recursive call  // to traverse the tree and compare // traverse left & right subtree's nodes // 
        bool left = isIdentical(r1 -> left, r2 -> left);
        bool right = isIdentical(r1 -> right, r2 -> right);
        
        //compare the value of two nodes
        bool value = r1-> data == r2-> data;
        
        //if everything is true, then return true else return false
        if(left && right && value) {
            return true;
        } else {
            return false;
        }
        
        
    }
};


int main() {

return 0;
}