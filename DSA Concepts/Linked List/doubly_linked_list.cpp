#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;     //NULL initially
    Node *prev;      //NULL initially

    //constructor
    Node(int d) {
        this -> data = d;
        this -> prev = NULL;    //NULL initially
        this -> next = NULL;    
    }

    //destructor to free up memory
    ~Node() {
        int value = this -> data;
        //memory free
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

//traversing
void print(Node *head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//get length
int getLength(Node *head) {
    int len = 0;
    Node* temp = head;

    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

//insert at head
void insertAtHead(Node* &head,Node* &tail, int d) {

    //empty list
    if(head == NULL) {
        Node *temp = new Node(d);
        head = temp;        //update head and tail
        tail = temp;
    }
    else {
        Node* temp = new Node(d);       //created a new node 'temp'
        temp -> next = head;            //pointed 'temp' (i.e newly inserted node's) next address to head(i.e first node initially created, but now its 2nd node as new node is inserted at head)
        head -> prev = temp;            // pointed head's (i.e first node initially created, but now its 2nd node as new node is inserted at head) prev to 1st node(i.e 'temp' => newly inserted node)
        head = temp;                    //updated head
    }
}

void insertAtTail(Node* &head,Node* &tail, int d) {

    //empty list
    if(tail == NULL) {
        Node *temp = new Node(d);
        tail = temp;    //update head and tail
        head = temp;    
    }
    else {
        Node* temp = new Node(d);       //create new node
        tail -> next = temp;        //point tail's next(i.e initiall last node's(but now 2nd last node) address to newly created node(i.e new last node))
        temp -> prev = tail;        //point temp (i.e newly created node)'s prev to tail(i.e 2nd last node)
        tail = temp;                // update tail 
    }
}

//insert at any given position
void insertAtPosition(Node *&tail, Node *&head, int position, int d) {

    int count = 1;      //create a count = 1 i.e 1st position
    Node *temp = head;      //temp that shall point at head (i.e first position)

    //insert at start // if we want to insert at start then....// check if position is 1 ..if yes then call insertAtHead() ....it would insert in head
    if(position == 1) {
        insertAtHead(head,tail, d);
        return;
    }

    //insert at last // if we want to insert at last then....// check if current node/object's next(i.e pointer) is NULL ..if yes then call insertAtTail() ....it would insert in tail
    if(temp -> next == NULL) {
        insertAtTail(head,tail,d);
        return;
    }
    
    //traverse through linked list (traverse till cnt i.e '1' is less than given 'position'-1)  //and to move further temp = temp->next (i.e temp = current object (jiske next(i.e pointer) main agle node ka address...toh update temp to next node ka address))
    while(count < position-1) {
        temp = temp->next;
        count++;
    }

    //create a new node for d
    Node* nodeToInsert = new Node(d);

    //visualize below in diagram
    //new node created i.e nodeToInsert (jiske next(pointer) main daldo temp(i.e current node) ke next(i.e agle node ke address)) // i.e newly created node shall point to 4th node
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;        //temp(i.e node previous to nodeToInsert) ke next ke prev(i.e temp ke aage ke node ka prev pointer) ko point karwao naya node se(nodeToInsert)
    temp -> next = nodeToInsert;                // temp(i.e node previous to nodeToInsert) ke next point karega nodeToInsert
    nodeToInsert -> prev = temp;                //nodeToInsert (new node created) ke prev point karega temp(i.e node previous to nodeToInsert)

}

void deleteNode(int position, Node *&head, Node *&tail) {

    //delete first or start node
    if(position == 1) {

        Node *temp = head;      // pointer temp pointing to the head(first node)
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;        //as we are allocating memory dynamically (i.e in heap) we must delete/free it 
 
    } else {

        //deleting any middle node or last node  // we'll create a previous and current node which shall point to current and previous nodes 
        Node *curr = head;          // pointer curr which points to head(first node) initally
        Node *prev = NULL;          // pointer prev which points to NULL initally

        int cnt = 1;        //counter
        //iterate from 1 to the position(i.e node to be deleted)
        while(cnt < position) {
            prev = curr;        //make prev = curr (i.e shift prev one step (i.e prev+1))
            curr = curr -> next;        // make curr = curr's next (curr next is pointing to next node) // i.e shift curr to next node (curr+1)
            cnt++;      //count++
        }

        if(curr -> next == NULL) {
            tail = prev;
        }

        curr -> prev = NULL;        //curr(node to be deleted) prev ko point karwao NULL se
        prev -> next = curr -> next;        //prev ka next ko point karwao curr k next (i.e next node)  //eg position = 3 ,, from above while loop curr on 3rd node & prev on 2nd node ,, point prev to curr's next(i.e 4th node)  //curr(eg 3rd node) ka wajood mita do
        curr -> next = NULL;            // curr node(i.e node to be deleted) point to NULL
        delete curr;                    // delete curr (i.e 3rd node)
    }
}

int main(){
/*
    Node *node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
*/

    //version 2
    Node* head = NULL;
    Node* tail = NULL;


    print(head);
    insertAtHead(head,tail, 11);
    print(head);

     insertAtHead(head,tail, 10);
    print(head);

    insertAtTail(head,tail, 12);
    print(head);

    insertAtPosition(tail, head, 3, 15);
    print(head);

    deleteNode(3,head, tail);
    print(head);


    cout <<  head -> data << endl;
    cout <<  tail -> data << endl;
    cout << "Length is " << getLength(head) << endl; 

return 0;
}