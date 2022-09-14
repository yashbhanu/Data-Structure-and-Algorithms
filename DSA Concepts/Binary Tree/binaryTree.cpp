#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// class for binary tree
class Node {

    public:
        int data;       // data that the node will have
        Node* left;     // pointer which points to the left child(i.e node) of parent node
        Node* right;    // pointer which points to the right child(i.e node) of parent node

    //constructor to initialize the root node (initially left and right shall be NULL)
    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};

// build a binary tree with help of recursion
Node* buildTree(Node* root) {

    cout << "Enter the data :" << endl;
    int data;           //take data for root node
    cin >> data;
    root = new Node(data);          // create a root node 

    if (data == -1) {               //if data is -1 then return NULL (i.e we dont need to create further nodes, hence returns NULL (i.e leaf nodes)) 
        return NULL;
    }

    cout << "Enter data for inserting in left of" << data << endl;
    root -> left = buildTree(root -> left);         // initialize left(i.e left pointer) of node using recursion to create as many nodes required (if data is passed as -1 , then function calls(i.e recursion stops) stops as it returns NULL and goes back)

    cout << "Enter data for inserting in right of" << data << endl;
    root -> right = buildTree(root -> right);       // initialize right(i.e right pointer) of node using recursion to create as many nodes required (if data is passed as -1 , then function calls(i.e recursion stops) stops as it returns NULL and goes back)

    return root;            //return root node

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

void reverseLevelOrder(Node *root) {

    if(root == NULL) return;    //check if NULL

    deque <Node *> q;   //create a deque of node type that would store the data and help traverse the tree via reverse  levels
    q.push_back(root);      //push_back the root node in deque

    stack<int> s;       //create a stack to reverse level order nodes 

    Node* curr = NULL;    // pointer to store the current node

    //loop till queue is empty
    while(!q.empty()) {

        //process each node
        curr = q.front();
        q.pop_front();

        //push the current node data into stack
        s.push(curr -> data);

        //if current node has left and right nodes(children) then push it into queue
        if(curr -> right) {
            q.push_back(curr -> right);
        }

        if(curr -> left) {
            q.push_back(curr -> left);
        }

    }

    //print all the elements from stack in reverse order
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

}

//use recursion
void inorder(Node *root) {

    //base case
    if(root == NULL) return;

    // LNR
    inorder(root->left);        //left
    cout << root -> data << " ";     //print node
    inorder(root->right);   //right
}

void preorder(Node *root) {

    //base case
    if(root == NULL) return;

    // NLR
    cout << root -> data << " ";     //print node
    preorder(root->left);        //left
    preorder(root->right);   //right
}

void postorder(Node *root) {

    //base case
    if(root == NULL) return;

    // LRN
    postorder(root->left);        //left
    postorder(root->right);   //right
    cout << root -> data << " ";     //print node
}


//2nd approach to build a tree i.e from levelOrder
void buildFromLevelOrder(Node* &root) {

    queue<Node*>q;          //queue to store data

    //get data for root node
    cout<< "Enter data for root " << endl;
    int data;
    cin >> data;

    root = new Node(data);      //create a new node(i.e root node) with the data

    q.push(root);           //push the root node to the queue

    //loop over till queue is empty
    while(!q.empty()) {

        //get the current node from queue's front(intially root node)
        Node* temp = q.front();
        q.pop();        //pop it

        //now take data from user to create left child of root node
        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;

        //if leftData is not -1(i.e non NULL), then create a new node to the left of temp(i.e curr/root node)
        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);       //and push the left node of temp(i.e curr/root node) in queue
        } 

         //now take data from user to create right child of root node     
        cout << "Enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;

        //if rightData is not -1(i.e non NULL), then create a new node to the right of temp(i.e curr/root node)
        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);      // and push the right node of temp(i.e curr/root node) in queue
        } 

    }

}

int main() {

    Node* root = NULL;          //pointer that points to NULL


    /*
    //creating a tree
    root = buildTree(root);         // pointer root shall point to root node created by buildTree(hence root is root node)

    //level Order traversal
    //levelOrderTraversal(root);         // level order traversal is a traversal technique of tree where tree is traversed using levels // 1st level1 , then level2, then level3

    // reverseLevelOrder(root);

    cout<< "Inorder traversal ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal ";
    preorder(root);
    cout << endl;

    cout<< "Postorder traversal ";
    postorder(root);
    */

   //creating a tree (approach 2)
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

return 0;
}