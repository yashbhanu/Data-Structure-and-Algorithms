#include <iostream>
using namespace std;

//approach 2
//create separate list for 0s 1s and 2s => 0 -> 0 // 1 -> 1 // 2 -> 2 -> 2
//merge the three list => 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> 2
// first create dummy nodes for 0s, 1s and 2s // and then insert the nodes from actual LL to dummy LL/nodes

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


void insertAtTail(Node* &tail, Node* curr) {
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head)
{
    //create dummy nodes and 2 pointers zeroHead and zeroTail pointing to it
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;      //curr at head
    //itearte LL
    while(curr != NULL) {
        int value = curr -> data;        //get value of curr node's data
        
        //create separate lists of 0s,1s,2s
        if(value == 0) {
        insertAtTail(zeroTail,curr);//insert it at dummy node's(zero's LL) tail
        }
        else if(value == 1) {
         insertAtTail(oneTail,curr);//insert it at dummy node's(one's LL) tail
        }
        else if(value == 2) {
         insertAtTail(twoTail,curr);//insert it at dummy node's(two's LL) tail
        }
        curr = curr -> next;
    }
    //created separate list for 0s, 1s , 2s
    //merge 3 sublist
    // incase 1st list empty
    //1st list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;        //point zero tail's next to one head's next(skipping the dummy node)
    }
    else {    //1st list is empty
        zeroTail -> next = twoHead -> next;     //point zeroTail ka next(skip dummy node) to twoHead ka next(skip dummy node) 
    }
    
    oneTail -> next = twoHead -> next;      //oneTail ka next point karwao twoHead ke next (dummy node skip) 
    twoTail -> next = NULL;         //twoTail ka next (i.e last node) point to NULL

    
    //setup head (at the start, skipping dummy node)
    head = zeroHead -> next;        
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}


int main(){

return 0;
}