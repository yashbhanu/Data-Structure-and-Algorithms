#include <iostream>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

// Problem => you have been given a binary search tree of integers with n nodes you are also given 39 key 39 which represents data of a node of this tree your task is to find the predecessor and successor of the given node in the bst
// givenn a bst with a key node // find the predecessor and successor of that key node

// Approach => 1. traverse and find the key 2. after you find the traverse and find the successor (successor = right subtree's minimum element) && predecessor (predecessor = left subtree's maximum element)

pair<int, int> predecessorSuccessor(BinaryTreeNode *root, int key)
{
    // find key in binary Tree
    BinaryTreeNode *temp = root;
    int pred = -1;
    int succ = -1;

    // loop till key is found
    while (temp->data != key)
    {
        // binary search // if temp's data is greater than go to left subtree & also save successor incase you find it
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        // binary search // if temp's data is smaller than go to right subtree & also save pred incase you find it
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }
    // now you have found the key && temp is pointing to key
    // pred // left subtree's max elem
    BinaryTreeNode *leftTree = temp->left; // got to left subtree & then towards right(bcz max elem is on right)
    // loop till the last as max elem is always the leaf node in a right subtree
    while (leftTree != NULL)
    {
        pred = leftTree->data;      // save data
        leftTree = leftTree->right; // keep traversing as max is on right
    }

    // succ  // right subtree's min elem //
    BinaryTreeNode *rightTree = temp->right; // got to right subtree & then towards left(bcz min elem is on left)
    // loop till the last as min elem is always the leaf node in a left subtree
    while (rightTree != NULL)
    {
        succ = rightTree->data;      // save data
        rightTree = rightTree->left; // keep traversing as min is on left
    }

    // create a pair and return ans
    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}

int main()
{

    return 0;
}