#include <iostream>
using namespace std;

//Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, and finally revert the changes to restore original tree. 
// we could go the previous nodes in binary tree easily using recursion(backtracking) and in iterative way , we use a queue which takes space complexity of O(n)
// but morris traversal helps us to achieve space complexity of O(1) by creating temporary links from current node to root/previous nodes

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void MorrisTraversal(struct Node* root)
{
    struct Node *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
        
        // if left doesnt exists print data and move right (bcz inorder LNR)
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
 
            // Find the inorder predecessor of current  //iterate towards left & find pre
            pre = current->left;
            //after going towards left, keep on moving right
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
            // if predecessor right is NULL, (i.e leaf node) , create a temporary link to current/root node && move current to its left
            if (pre->right == NULL) {
                pre->right = current;       //temp link
                current = current->left;    // move/iterate towards left (bcz Inorder traversal)
            }
 
            //Revert the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor 
            // revert the  temporary links on the right leaf nodes and make it NULL again // print node // && move towards right (bcz inorder LNR)
            else {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}


int main() {

return 0;
}