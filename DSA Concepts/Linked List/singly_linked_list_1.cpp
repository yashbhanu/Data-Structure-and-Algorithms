#include <iostream>
using namespace std;

class Node {

    public:
    //data of the linked list
    int data;

    //pointer to the next node of linked list // the pointer is of type 'Node' (rather than int, char) i.e class
    Node* next;             // as pointer is pointing to another node(i.e ) // type of pointer would be 'Node' i.e class

    //constructor
    Node(int data) {
        this -> data = data;
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

//insert new node at linked list's head
void insertAtHead(Node *&head, int d) {

    //new node create (i.e dynamically create an object)
    Node *temp = new Node(d);
    temp -> next = head;        //now as we want to point towards head (i.e first position) // temp is a object so temp ka 'next' (i.e uss object ka next(i.e a pointer) == head (head is also a pointer which stored address of 1st node (i.e node 1) i.e hum ek naya node create kar rhe h (i.e temp) jiska data rahega 'd' && jiska address (i.e next (pointer)) rahega 'head' jisme pehle wale node (node1) ka address store rahega ) so new node temp will point to node no. 2 address )
    head = temp;                // now as we have inserted at head , we need to update head// head = temp (i.e head pointer will point at address of 'temp' (i.e first node)
}

//insert new node at linked list's tail
void insertAtTail (Node *&tail, int d) {
    //new node create (i.e dynamically create an object)
    Node *temp = new Node(d);
    tail -> next = temp;        // ' tail -> next ' means tail's(i.e previous object/node's next (i.e pointer) pointing to last/tail node's (i.e temp) address) // second last node point karega last node ko
    tail = temp;            //update tail to temp (i.e currently/newly created node (i.e last/tail node))
}

//insert at any given position
void insertAtPosition(Node *&tail, Node *&head, int position, int d) {

    int count = 1;      //create a count = 1 i.e 1st position
    Node *temp = head;      //temp that shall point at head (i.e first position)

    //insert at start // if we want to insert at start then....// check if position is 1 ..if yes then call insertAtHead() ....it would insert in head
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    //insert at last // if we want to insert at last then....// check if current node/object's next(i.e pointer) is NULL ..if yes then call insertAtTail() ....it would insert in tail
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return;
    }
    
    //traverse through linked list (traverse till cnt i.e '1' is less than given 'position'-1)  //and to move further temp = temp->next (i.e temp = current object (jiske next(i.e pointer) main agle node ka address...toh update temp to next node ka address))
    while(count < position-1) {
        temp = temp->next;
        count++;
    }

    //create a new node for d
    Node* nodeToInsert = new Node(d);

    //new node created i.e nodeToInsert (jiske next(pointer) main daldo temp(i.e current node) ke next(i.e agle node ke address)) // i.e newly created node shall point to 4th node
    nodeToInsert -> next = temp -> next;

    //temp -> next (i.e agle node ka address) ko point karwao nextToInsert se (i.e newly created node) //i.e 2nd node will point tp newly created node shall point (i.e 3rd node)
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node *&head, Node *&tail) {

    //delete first or start node
    if(position == 1) {

        Node *temp = head;      // pointer temp pointing to the head(first node)
        head = head->next;      //as head is pointing to the first node // so we shall update head to the 2nd node , so it'll become first && free memory of first node
        //memory free start node
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
    
        prev -> next = curr -> next;        //prev ka next ko point karwao curr k next (i.e next node)  //eg position = 3 ,, from above while loop curr on 3rd node & prev on 2nd node ,, point prev to curr's next(i.e 4th node)  //curr(eg 3rd node) ka wajood mita do
        curr -> next = NULL;            // curr node(i.e node to be deleted) point to NULL
        delete curr;                    // delete curr (i.e 3rd node)
    }
}


void print(Node * &head) {
    Node*temp = head;       //create a temp pointer that points at first node (i.e head)

    //last node is always pointing at NULL // so iterate till last node
    while(temp != NULL) {
        cout << temp -> data << "->";        //cout temp's (i.e current node/object's) data
        temp = temp -> next;                //update temp (i.e move forward) // as current linked list node/object has a data && address of next node // temp = temp's(current node's) next(pointer which has address of next node/object) 
    }
    cout << endl;
}


int main(){

    Node* node1 = new Node(10);       //dynamically create a object for class 'Node'

    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    //head pointing to node1  // node1 is a class's object interpreted as linked list data structure which is a memory block somehwere in memory and *head is pointing to the address of that memory block (i.e object = node1)
    Node *head = node1;
    print(head);

    insertAtHead(head,12);

    print(head); 

    //created a 'tail' pointer that points to current node/object (i.e node1)
    Node *tail = node1;
    insertAtTail(tail, 11);
    print(head);

    //insert at position 3 where data = 2
    insertAtPosition(tail, head, 3, 2);
    print(head);

    //delete
    deleteNode(4, head, tail);
    print(head);

    cout << head -> data << endl;
    cout <<  tail -> data << endl; 

return 0;
}