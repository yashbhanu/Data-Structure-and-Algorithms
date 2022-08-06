#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//approach 1 => T.C & S.C = O(n)
// we need to clone/copy a LL // but here the structrue of LL is diff. // we have the data & next part in LL as usual, but we also have an additional part i.e arb(a random pointer pointing to any random LL node)
// first we clone the LL with data and next wala part by while loop & insertAtTail() func // now we only have to assign random pointers to clone LL node's same as origina LL node's
// hence we save the random(i.e arb) pointer using map // we use map DS to map original LL node to clone LL node (originalNode : cloneNode) and thus we save the random(i.e arb) pointers
// now we assign random(i.e arb) pointers to clone LL using while loop with the help of saved nodes in map DS

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
    private:
    
        void insertAtTail(Node* &head, Node* &tail, int data) {
            Node* newNode = new Node(data);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
                return;
            }
            else {
                tail -> next = newNode;
                tail = newNode;
            }
        }
        
    public:
    Node *copyList(Node *head)
    {
        // step 1 : create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp -> data);           //clone the original LL (only data and next part)
            temp = temp -> next;
        }
        
        //Step 2 : create a map (i.e map node of original LL to node of clone LL)
        unordered_map<Node*, Node*> oldToNewNode;
        
        Node* originalNode = head;          //pointer at head of orginalNode
        Node* cloneNode = cloneHead;        //pointe at head of cloneNode
        
        //iterate the originalNode && cloneNode
        while(originalNode != NULL && cloneNode != NULL) {
            oldToNewNode[originalNode] = cloneNode;             //map the orginalNode to cloneNode (save orginalNode : cloneNode)
            originalNode = originalNode -> next;            // move forward
            cloneNode = cloneNode -> next;
        }
        
        //STep 3 : placed the random(i.e arb pointers)
        originalNode = head;            //reassign orginalNode & cloneNode at their respective heads
        cloneNode = cloneHead;
        //iterate original Node and
        while(originalNode != NULL) {
            cloneNode -> arb = oldToNewNode[originalNode -> arb];           //...assign random pointer(i.e arb) of cloneLL to original LL's random(i.e arb) pointer which is saved in map
            originalNode = originalNode -> next;            //move forward
            cloneNode = cloneNode -> next;
        }
        
        return cloneHead;
    }

};

int main() {

return 0;
}