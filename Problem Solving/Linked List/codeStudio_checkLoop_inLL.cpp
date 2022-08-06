#include <iostream>
#include <map>
using namespace std;

//VERY IMP => interview pov

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
};

void insertAtHead(Node *&head, int d) {

    //new node create (i.e dynamically create an object)
    Node *temp = new Node(d);
    temp -> next = head;        //now as we want to point towards head (i.e first position) // temp is a object so temp ka 'next' (i.e uss object ka next(i.e a pointer) == head (head is also a pointer which stored address of 1st node (i.e node 1) i.e hum ek naya node create kar rhe h (i.e temp) jiska data rahega 'd' && jiska address (i.e next (pointer)) rahega 'head' jisme pehle wale node (node1) ka address store rahega ) so new node temp will point to node no. 2 address )
    head = temp;                // now as we have inserted at head , we need to update head// head = temp (i.e head pointer will point at address of 'temp' (i.e first node)
}

void insertAtTail (Node *&tail, int d) {
    //new node create (i.e dynamically create an object)
    Node *temp = new Node(d);
    tail -> next = temp;        // ' tail -> next ' means tail's(i.e previous object/node's next (i.e pointer) pointing to last/tail node's (i.e temp) address) // second last node point karega last node ko
    tail = temp;            //update tail to temp (i.e currently/newly created node (i.e last/tail node))
}



//check LOOP/cycle in LL
//approach 1 => create a map data structure (key-value pairs) => and iterate the LL and keep marking nodes as true or false(visited or not visited) // and if it has loop it'll reach the node which is already marked 'true', hence exit
bool isCyclic(Node *head) {

    //empty list
    if(head == NULL) {
        return true;
    }

    //create a map with key as 'Node*' (i.e pointer of the node) && key as 0 ,1 (visited or not visited)
    map<Node*, bool> visited;

    Node *temp = head;

    //iterate LL till its not NULL 
    while(temp != NULL) {

        //cycle is present // idf visited[temp] == true (i.e already marked true) ,, then return true(is cyclic)
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;       //if its not already marked as true , then mark it as true(i. visited) and
        temp = temp -> next;        //move to next node
    }

    //if it finds NULL and exits loop then its not cyclic/loop ,, hence return false
    return false;
}

// approach 2 => floyd's cycle // create a slow pointer and fast pointer // slow moves 1 step // fast moves 2 steps // if its loop then slow and fast will meet at somepoint (i.e slow == fast)
Node* floydCycleDetectionLoop(Node* head) {

    //empty list
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    //iterate till slowor fast reaches NULL
    while(slow != NULL && fast != NULL) {

        // move fast 2 steps
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        //move slow 1 step
        slow = slow -> next;

        //if they meet then there is a loop
        if(slow == fast) {
            cout << "present at " << slow -> data << endl;
            return slow;
        }
    }
    //if slow or fast hits NULL then there is no cycle and it'll come out of loop// hence return NULl
    return NULL;
}


//detect the start node of the loop
Node* getStartingNode(Node* head) {

    //empty list
    if(head == NULL)
        return NULL;

    //we get the pt. of intersection where slow met fast and detected that its a loop
    Node* intersection = floydCycleDetectionLoop(head);
    Node* slow = head;          //pointer at head

    //now we have slow at head and and a pointer at the pt of intersection // now move slow 1 steps forward && move intersection 1 steps forward  run a loop till slow meets pt of intersection (acc. to formula shown in lec 47, pt. where slow == intersecton will be the start of cycle/loop)
    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;        //as slow == intersection happens(i.e we found start node) , exit from while loop // hence return slow(i.e start node)
}


//remove loop => jo node wapis se LL k ksii node ko point kar rha h (i.e creating loop) , us node ko point karwao NULL se
void removeLoop(Node *head) {
    //empty list
    if(head == NULL)
        return;

    //get start of the loo[]
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;       //create a temp poinitng to start of loop

    //iterate the cycle/loop by temp(i.e startOfLoop) till temp reaches startOfLoop(as its cyclic) 
    while(temp -> next != startOfLoop) {
        temp = temp -> next;        //aage badhate jao temp ko
    }
    //as we exit while loop , our temp -> next is pointing to startOfLoop // make it NULL to remove loop
    temp -> next = NULL; 

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


int main() {

    Node* node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head,12);
    insertAtTail(tail,11);
    insertAtTail(tail,13);
    insertAtTail(tail,14);

    // print(head);

    //created a loop // last elem ko point karwa diya 2nd elem ko
    tail -> next = head -> next;

    // if(isCyclic(head)) {
    //     cout << "Its a looped LL " << endl;
    // } else {
    //     cout << "Its not a looped LL " << endl;
    // }

    if(floydCycleDetectionLoop(head)) {
        cout << "Its a looped LL " << endl;
    } else {
        cout << "Its not a looped LL " << endl;
    }

    Node* loop = getStartingNode(head);
    cout << "The start node of loop is " << loop -> data << endl;

    removeLoop(loop);
    print(head);

return 0;
}