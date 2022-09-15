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

//Problem => Given a binary tree, find if it is height balanced or not. 
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree (i.e(height(left) - height(right) <= 1)
//Approach => create a pair (i.e returns two values) which returns <isBalanced(i.e true/false), height>
// make recursive calls for every node and check its left and right nodes // extract the ans if true/false (i.e isbalanced or not) // check the condition for height i.e (height(left) - height(right) <= 1)
// set the height for subtree //check if everything is true(if yes, then its balanced), return TRUE else FALSE
// dry run to understand better

class Solution{
    public:
    
    pair<bool,int> isBalancedFast(Node *root) {
        
        //base case  // if root is NULL then a create a pair ( true(i.e isBalanced or not , height))
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        //recursive call  // create a pair left and right and call the function for right and left subtree that shall return (true/false, height) for every node
        pair<int , int > left = isBalancedFast(root -> left);
        pair<int, int > right = isBalancedFast(root -> right);
        
        bool leftAns = left.first;          //extract isBalanced or not for left pointer/side of a node 
        bool rightAns = right.first;        //extract isBalanced or not for right pointer/side of a node 
        
        bool diff = abs (left.second - right.second) <= 1;          //condition to check if Balanced or not acc. to condition provided in question // left.second has height of left side of node and vice versa // abs will give value in boolean(true or false) 
        
        pair<bool,int> ans;
        ans.second = max(left.second , right.second) + 1;           // set height of the node
        
        //check if all are true // if yes then ans.first = true(i.e is balanced)
        if(leftAns && rightAns && diff) {
            ans.first = true;
        }
        // if not, then ans.first = false(i.e is not balanced)
        else {
            ans.first = false;
        }
        
        return ans;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;      // call function and return first value returned from the pair (i.e true or false)
    }
};

int main() {

return 0;
}