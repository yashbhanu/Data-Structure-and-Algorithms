#include <iostream>
#include <queue>
using namespace std;


// Binary search Tree => Similar to binary search // where for each node, values in left subtree are smaller than root node's data // and for each node values in right subtree are greater than root node's data

class Node {

    public:
    //properties of class Node
        int data;
        Node* left;
        Node* right;
    
    //constructor
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* insertIntoBST(Node* root, int data) {         // T.C O(logn)
    //base case // for root node , if root is NULL then create a new node and return it
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    // root node already exists 
    if(data > root->data) {
        //if data is greater than root node's data, then... //insert into right part // recursion
        root -> right = insertIntoBST(root -> right, data);
    }
    else {
        //if data is smaller than root node's data, then... //insert into left part // recursion
        root -> left = insertIntoBST(root -> left, data);
    }
}

void takeInput(Node* &root) {

    int data;
    cin >> data;        // for initally root node // take data from user

    // loop over and keep adding data into BST till user inputs -1(i.e end of BST)
    while(data != -1) {
        root = insertIntoBST(root, data);           // insert into BST by passing root node and data which shall return a node
        cin >> data;                                // keep taking data from user till its -1
    }
}

void levelOrderTraversal(Node *root) {

    queue<Node *> q;        //we'll make a queue of node type that would store the data and help traverse the tree via levels
    q.push(root);           //push the root node in queue
    q.push(NULL);           //whenever the level is over, and we want to go to the next level, we initialize a separator(i.e NULL), so whenever NULL occurs in the queue, we know that we must go the next level

    //traverse queue till its empty
    while(!q.empty()) {
        Node* temp = q.front();     //get the node in front of the queue
        q.pop();                    //remove the node from the queue
    
        // if temp is NULL, that is a separator has occured, and we must go to the next level
        if(temp == NULL) {

            //enter to go next level
            cout << endl;

            //temp is NULL, we went to the next level, still if queue isnt empty, i.e next level exists => add a separator 
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            //print the node's data
            cout << temp -> data << " ";

            //if the node has left and right nodes(i.e children), then push that left and right nodes in the queue , those nodes will be printed in the next level
            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

Node* minVal(Node* root) {
    Node* temp = root;

    // keep on moving leftwards until we reach the leaf node on left(As smaller values in BST are in left)
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;

    // keep on moving rightwards until we reach the leaf node on right(As larger values in BST are in right)
    while(temp -> right != NULL) {
        temp = temp -> right;
    }
    return temp;
}

//DELETION of a node => V.V. IMP for interviews
Node* deleteFromBST(Node* root, int val) {

    //base case
    if(root == NULL)
        return root;

    // if the node to be deleted is found then proceed
    if(root -> data == val) {

        // node with 0 child // 0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;            // simply return root
            return NULL;            // and return NULL
        }

        //node with 1 child //1 child

        //node with 1 child on left //left child
        if(root -> left != NULL && root -> right == NULL) {
            Node *temp = root -> left;          // store left child of root(node to be deleted)
            delete root;                        // delete root(node to be deleted)
            return temp;                        // return temp(left child of  the deleted node) // so it would move upwards
        }

        //node with 1 child on right //right child
        if(root -> left == NULL && root -> right != NULL) {
            Node *temp = root -> right;
            delete root;
            return temp;
        }

        //node with 2 child //2 child
        if(root -> right != NULL && root -> left != NULL) {
            // Two methods -> find the min value on right subtree OR the max value on left subtree and replace it root node(node to be deleted)
            // here we have used 1st method to find the min value on right subtree
            int mini = minVal(root -> right) -> data;                // find the min value on right subtree
            root -> data = mini;                                    // replace with root node's data
            root -> right = deleteFromBST(root -> right, mini);         // delete the min value node as its replaced with the deleted node
            return root;
        }
    }
    else if ( root -> data > val) {
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else if ( root -> data < val) {
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }

}


int main() {

    Node* root = NULL;          //initially take a pointer root and point it to NULL

    cout << "Enter data to create BST " << endl;
    takeInput(root);            // take the input by passing root node

    cout << "Printing BST " << endl;
    levelOrderTraversal(root);          // print BST using level order traversal

    cout << "Min val is " << minVal(root) -> data <<endl; 
    cout << "Max val is " << maxVal(root) -> data <<endl; 

    //DELETION
    root = deleteFromBST(root,7);

    cout << "Printing BST " << endl;
    levelOrderTraversal(root);

return 0;
}