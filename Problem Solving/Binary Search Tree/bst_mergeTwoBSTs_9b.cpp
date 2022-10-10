#include <iostream>
using namespace std;

class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                this -> left = NULL;
                this -> right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

// Problem => merge two BSTs // Do in T.C O(m+n) && S.C O(h1 + h2)
// Approach => 1. Convert both BSTs to sorted Doubly Linked Lists  2. Merge two sorted Linked Lists into a single sorted Linked List  3. Convert the Linked List into BST


void convertIntoSortedDLL(TreeNode *root, TreeNode* &head) {
    
    //base case
    if(root == NULL)
        return ;

    //use recursion and convert right subtree into sorted LL
    convertIntoSortedDLL(root -> right,head);
    //sorted LL shall return a head of the LL // point root's right(i.e next) to head of LL(converted from right subtree)
    root -> right = head;
    
    // if head of LL is not NULL , then point head's left(i.e previous) to root bcz is double linked list
    if(head != NULL)
        head -> left = root;
    
    //update head to root
    head = root;
    
    //use recursion and convert left subtree into sorted LL
    convertIntoSortedDLL(root -> left,head);
}


TreeNode* mergeLinkedList(TreeNode *head1, TreeNode *head2) {
    
    TreeNode* head = NULL;          // two pointer head & tail of linked list(initially NULL)
    TreeNode* tail = NULL;
    
    // both heads of LinkedList should not be NULL
    while(head1 != NULL && head2 != NULL) {
        //compare the data // if head1(LL 1's data) is smaller than head2(LL 2's data) then, head1->data will be at start
        if(head1->data < head2->data) {
            if(head == NULL) {      //if its first node, then
                head = head1;       // head pointer at head1(first node of LL)
                tail = head1;       // tail also at head1
                head1 = head1 -> right;             // move head1 forward to iterate LL
            }
            else {                   //if its not first node, then, insertAtTail
                tail -> right = head1;          // tail's right(i.e next) to head1(the node to be inserted at tail)
                head1 -> left = tail;           // head1's(the node to be inserted at tail) left(i.e prev) pointing to tail(i.e previous node)
                tail = head1;                   // update tail & pt. it to last node(i.e newly inserted node in tail)
                head1 = head1 -> right;         // move head1 forward to iterate
            }
        }
        else {                  // if head2 is smaller, then same process as above
            if(head == NULL) {
                head = head2;
                tail = head2;
                head2= head2 -> right;
            }
            else {
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2 -> right;
            }
        }
    }
    // if LL 2 has iterated completely, but some elem in LL 1 remain // then process remaining elems of LL 1
        while(head1 != NULL) {
                tail -> right = head1;
                head1 -> left = tail;
                tail = head1;
                head1 = head1 -> right;
        }
        // process remaining elems of LL 2
        while(head2 != NULL) {
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2 -> right;
        }
        return head;
}

//count no. of nodesin LL
int countNodes(TreeNode *head) {
    int cnt = 0;
    TreeNode* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp -> right;
    }
    return cnt;
} 

// convert sorted LL into BST
TreeNode* sortedLLToBST(TreeNode* &head, int n) {
    
    //base case 
    if(n <= 0 || head == NULL)
        return NULL;
    
    // Approach => you have a sorted LL -> use binary search approach -> convert first half elems of LL (i.e n/2) into left subtree -> convert mid elem(i.e node on which head is poiting to) into root node
    // -> convert the remaining elems(i.e n(no. of LL nodes) - 1(root node) - n/2(left subtree) -> formual to obtain remaining elems) into right subtree

    TreeNode *left = sortedLLToBST(head, n/2);          // convert n/2(first half elems of LL) into left subtree  // which shall return a pointer(i.e *left) to left subtree
    TreeNode *root = head;  
    
    
    root -> left = left;            // root's left pointing to left subtree
    head = head -> right;           // move head forward to iterate LL
    
    root -> right = sortedLLToBST(head, n-n/2-1);           // convert remaining elems of LL( n-n/2-1) into right subtree of root
    return root;                                            // return root of BST
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2){
    //convert BST into sorted DLL : in-place S.C O(1)
    //BST 1
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1 -> left = NULL;
    //BST 2
    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2 -> left = NULL;
    
    //merge sorted LinkedList // which returns head of sorted LinkedList
    TreeNode* head = mergeLinkedList(head1, head2);
    
    //convert SLL to BST  //pass head of LinkedList 
    return sortedLLToBST(head, countNodes(head));
    
}

int main() {

return 0;
}