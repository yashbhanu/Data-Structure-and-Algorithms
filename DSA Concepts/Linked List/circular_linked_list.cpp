#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;     //NULL initially

    //constructor
    Node(int d) {
        this -> data = d;
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

void insertNode(Node *&tail, int element, int d) {

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);        //if list is NULL, then create new node
        tail = newNode;                     // point tail towards newNode(i.e first node) created
        newNode -> next = newNode;          // point newNode's next(i.e pointer) to itself(bcz its circular LL)
    }
    else{ 

        //non-empty list
        //assuming that the element is present in the list
        Node* curr = tail;      //create a pointer 'curr' which points to tail

        //we'll input new nodes by comparing it to existing elements  // iterate the LL till you find the right elem // eg " 3->4->5 " here's a LL , we need to add a node after 4 ,, so element = 4 // 4 elem ke aage dalo naya node // iterate LL till you reach '4'
        while(curr->data != element) {
            curr = curr -> next;
        }

        //element found -> curr is representing element wala node (eg curr = 4 in " 3->4->5 ")
        Node* temp = new Node(d);       //create new node   
        temp -> next = curr -> next;    // temp (i.e new node)'s next ko point karwao curr(i.e previous node) ke next se 
        curr -> next = temp;            //curr(i.e previous node to temp (i.e new node)) ke next ko point karwao temp(i.e new node) se 
    }
}

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << "List is empty " << endl;
        return;
    }
    else {
        //non-empty
        //assuming that "value" is present in the Linked list
        Node* prev = tail;      //created a previous pointer that points to tail
        Node* curr = prev -> next;      // curr pointer that points to prev's next (i.e current)

        // we'll give value as the input and delete the node with that value // iterate till you reach the value
        while(curr -> data != value) {
            prev = curr;        //move prev one node further(prev + 1)
            curr = curr -> next;        //move curr one node further(curr + 1)
        }

        prev -> next = curr -> next;        //point prev's next to curr's next

        //single node deletion // if there is single node then curr and prev will be same ,, hence tail = NULL as we are deleting curr
        if(curr == prev) {
            tail = NULL;
        }

        //update tail
        if(tail == curr) {
            tail = prev;
        } 

        curr -> next = NULL;        // curr's next = NULL as we are going to delete it
        delete curr;                    
    }
}

void print(Node* &tail) {

    Node* temp = tail;      //temp pointer will point to tail

    //empty list
    if(tail == NULL) {
        cout << "List is empty " << endl;
        return;
    }

    // do while loop // it will first print tail ka data and then keep iterating and printing data of nodes till it reaches tail again and then stop
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
}

//check if LL is circular or not
bool isCircular(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    //create a pointer temp pointing at head's next(i.e 2nd node)
    Node* temp = head -> next;
    //start iterating from 2nd node // check if its NULl (if NULL then break) && check if temp == head , then break (as we iterated the whole LL)
    while(temp != NULL && temp!=head) {
        temp = temp -> next;        //move forward
    }

    //if the whole LL is iterated then it'll stop at head and head and temp will be at same position(head == temp) (indicated that there is no NULL and LL is circular) // hence true
    if(temp == head) {
        return true;
    }

    //else false
    return false;
}


int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 3);     // 5 is any random elem which isn't of any use as list is empty (tail == NULL)
    print(tail);

    insertNode(tail, 3, 4);     // 3 ke aage 4 dal do
    print(tail);

    insertNode(tail, 4, 9);     // 4 ke aage 9 dal do
    print(tail);

    insertNode(tail, 3, 1);
    print(tail);

    deleteNode(tail,4);     //delete
    print(tail);

return 0;
}