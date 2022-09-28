#include <iostream>
using namespace std;

// Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed. After flattening, left of each node should point to NULL and right should contain next node in preorder.
// Convert a binary tree into linked list in a preorder manner/traversal(As mentioned in question) && left node should point to NULL(as mentioned in question)

//Do it O(1) S.C    // use Morris traversal to traverse in preorder manner/traversal // cannot use recursion or queue // hence simply change the links to achieve of O(1) S.C
//dry run to understand better // ref => https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

struct Node {
	int key;
	Node *left, *right;
};

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;      //curr pointer which points to root node
        while(curr != NULL) {
            
            if(curr -> left) {          //if left exists
                Node* pred = curr -> left;              // create pointer pred to curr's left
                // after one steps towards left, keep on moving right(bcz preorder NLR) //if right exists, keep on moving right
                while(pred -> right) {
                    pred = pred -> right;
                }
                pred -> right = curr -> right;          //as right becomes NULL(leaf node), change the link make it point to curr's right(i.e right subtree of binary tree)
                curr -> right = curr -> left;           // now change curr's right(pointer to right subtree) towards curr's left(i.e left subtree)
                curr -> left = NULL;                    // curr's left should be NULL(as mentioned in question)
            }
            curr = curr -> right;                   // keep moving towards right (as curr's right is pointing to left subtree) // keep traversing and changing links
        }
    }
};

int main() {

return 0;
}