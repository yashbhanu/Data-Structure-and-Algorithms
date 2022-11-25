#include <iostream>
using namespace std;


    // Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

#include <queue>
class compare {
    public:
        bool operator()(Node<int>* a, Node<int>* b) {
            return a->data > b->data;
        }
};


// IMP question
// Problem => Merge K Sorted Arrays | You would be given an array with heads(i.e 1st elem) of all LL's eg.arr = [head1LL, head2LL, head3LL,k] | You need to marge all the linked list together
//  so , first create a min heap and insert all the starting elem 1st elem (i.e heads of LL) of all LL in it | insert it in the form of nodes |  // insert all start/1st elem i.e head of all LL in the minHeap 
// minHeap will put the smallest elem at the top (bcz dats what minHeap do) | create two pointer head & tail for new ans LL | now till minHeap is empty, extract the top node in minHeap(i.e smallest value node in LL) & pop it from minheap
// now you have a top pointer poiting to smallest node of LL // iterate top's(i.e smallest LL node) Linkedlist and push all the next nodes in the LL it into minHeap | minHeap shall bring smallest on top
// now you have top , insert it into new LL , if head is NULL i.e ans LL is empty , then point head and tail both at top | if head!=NULL i.e LL is not empty -> attach new smallest node to LL by tail's next  
//  loop over the all The LL's nodes , keep pushing into minHeap & fetching smallest node from it and attaching it to ans LL // return head (i.e head of new sorted LL)
// dry runn to understand better


Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>* , vector<Node<int>*>, compare > minHeap;              // create priority queue
    
    int k = listArray.size();           // no. of LL's , i.e no. of heads in array
    // if no LL exists, return NULL
    if(k == 0)
        return NULL;
    
    //step 1 : push all the heads of LL (i.e 1st elem of LL) into minHeap
    for(int i = 0; i < k; i++) {
        if(listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }
    
    // pointer of new ans LL
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    
    // loop till minHeap is empty -> i.e loop over all LL nodes and keep pushing & popping from minHeap 
    while(!minHeap.empty()) {
        Node<int>* top = minHeap.top();             // get smallest node/elem from minHeap
        minHeap.pop();                              // pop it
        
        // if dat smallest node/elem's respective LL have next elem , then push it into minHeap // extract top(smallest) & attach it new LL
        if(top -> next != NULL) {
            minHeap.push(top -> next);
        }

        // attach top(smallest node/elem) to new ans LL
        //ans LL is empty , then assign head & top
        if(head == NULL) {
            head = top;
            tail = top;
        }
        // if LL is not empty , insert/attach top(smallest) in LL by tail-> next 
        else {
            tail -> next = top;         // attach new node to LL
            tail = top;             // update tail in new ans LL
        }
    }
    // return head of new ans LL
    return head;
}


int main() {

return 0;
}