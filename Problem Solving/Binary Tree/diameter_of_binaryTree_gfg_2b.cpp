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

class Solution {
    
   pair<int, int> diameterFast(Node* root) {
       
       //base case
       if(root == NULL) {
           pair<int, int> p = make_pair(0,0);
           return p;
       }
       
       pair<int, int> left = diameterFast(root -> left);
       pair<int, int> right = diameterFast(root -> right);
       
       int opt1 = left.first;
       int opt2 = right.first;
       int opt3 = left.second + right.second + 1;
       
       pair<int, int> ans;
       ans.first = max(opt1, max(opt2, opt3));
       ans.second = max(left.second, right.second) + 1;
       
       return ans;
   }
    
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        return diameterFast(root).first;
    }
};

int main() {

return 0;
}