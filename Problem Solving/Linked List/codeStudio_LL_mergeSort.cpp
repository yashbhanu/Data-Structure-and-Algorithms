#include <iostream>
using namespace std;
#include <bits/stdc++.h>

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };


// we want to sort the LL using merge sort => hence break down the LL into 2 parts => continue to break it down till it reaches a single node using recursion
// => sort the nodes and keep on merging it using recursion

//find mid using slow & fast approach
node* findMid(node* head) {
    node* slow = head;
    node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

//sort and merge 
node* merge(node* left, node* right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    node* ans = new node(-1);        //create a dummy node and keep on joining new nodes (i.e our sorted LL nodes)
    node* temp = ans;               // pointer at dummy node
    
    //sort and merge the LL's (iterate the left and right part)
    while(left != NULL && right != NULL) {
        //sorting(if left's data is less than right's data, then add(join) the left node to temp(dummy node)(i.e creating a new sorted LL by adding new nodes to dummy node by sorting))
        if(left -> data < right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        //sorting(if right's data is less than left's data, then add(join) the right node to temp(dummy node)(i.e creating a new sorted LL by adding new nodes to dummy node by sorting))
        else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    // in case right part is 2nodes and left is 3nodes // we need to add the extra node after we exit the above while loop(terminating as right part is completed)
    while(left != NULL) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        
    // in case right part is 3nodes and left is 2nodes // we need to add the extra node after we exit the above while loop(terminating as left part is completed)
    while(right != NULL) {
            temp -> next = right;
            temp = right;
            right = right -> next;
      }
    // update ans as dummy node's next (sorted LL node) (eradicate dummy node and return sorted LL)
    ans = ans -> next;
    return ans;
}

node* mergeSort(node *head) {
    //base case
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    
    node* mid = findMid(head);        //find mid of LL
    
    //break LL into 2 parts
    node* left = head;
    node* right = mid -> next;
    mid -> next = NULL;

    //break down LL it into further indiviual parts till it becomes single nodes
    left = mergeSort(left);
    right = mergeSort(right);
    
    //sort them and merge them one by one 
    node* result = merge(left, right);
    
    return result;
}


int main() {

return 0;
}