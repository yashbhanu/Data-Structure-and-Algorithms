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

//Approach 2 => T.C O(N)
//diameter of binary tree (i.e maximum distance(i.e max nodes) between two end nodes(i.e root & leaf nodes OR leaf nodes & leaf nodes))
//approach 1 => the distance(i.e path) exists in only right part of tree or only right part of tree OR combined in right and left tree
//hence, opt 1 => get max distance on complete left subtree, opt 2 => get max distance on complete right subtree, opt 3 => get max height of left subtree, right subtree and + 1 (add root node)
// ans  = max of (opt 1, opt 2, opt 3)
//Instead of calling 2 different functions for height and diameter which gives T.C O(N), create a pair (i.e returns 2 values together) and return height and diameter together in a pair dat which reduces T.C



class Solution {
    
   pair<int, int> diameterFast(Node* root) {
       
       //base case
       if(root == NULL) {
        // if root is NULL , create a pair of (0,0) and return it
           pair<int, int> p = make_pair(0,0);
           return p;
       }
       
       //recursive call
       // create a pair and call function for left subtree and right subtree of node
       pair<int, int> left = diameterFast(root -> left);
       pair<int, int> right = diameterFast(root -> right);
       
       int opt1 = left.first;       //left side diameter
       int opt2 = right.first;      //right side diameter
       int opt3 = left.second + right.second + 1;           //height of the node
       
       pair<int, int> ans;
       ans.first = max(opt1, max(opt2, opt3));          //return diameter (i.e max of 3 opts)
       ans.second = max(left.second, right.second) + 1;         // return height of the node
       
       return ans;      //return pair where ans.first = diameter, ans.second = height
   }
    
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        //call diameter function and pass root to it // and return the pair's first part(i.e diameter)
        return diameterFast(root).first;
    }
};

int main() {

return 0;
}