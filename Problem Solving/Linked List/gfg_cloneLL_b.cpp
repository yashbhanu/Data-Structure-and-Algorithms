#include <iostream>
using namespace std;
#include <bits/stdc++.h>


//approach 2 => T.C = O(n) & S.C = O(1)
// we need to clone/copy a LL // but here the structrue of LL is diff. // we have the data & next part in LL as usual, but we also have an additional part i.e arb(a random pointer pointing to any random LL node)
//here we change the links of the pointers to avoid creating any space and get a TC of O(1)
//step 1 : first we clone the LL with data and next wala part by while loop & insertAtTail() func // now we only have to assign random pointers to clone LL node's same as origina LL node's
//step 2 : cloneNodes add in between original list (change the links of original and clone LL) // original LL will point to clone LL node && clone LL node will point to original LL node // LL will be like = 1->1->2->2->3->3->4->4->//see the diagram in lec 52 video
//step 3: assignment of random pointer // clone list ka random pointer = orginal list ka random pointer ka next(as we have assigned original LL node pointing to clone LL)
//step 4 : revert the changes (bring back the positions(next pointers) of original and clone LL back to previous(original) state) // i.e original LL = 1->2->3->4  &&  cloneLL = 1->2->3->4 


/* Link list Node */
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
        
        //step2 : cloneNodes add in between original list (change the links of original and clone LL)
        Node* originalNode = head;              //respective head at orginal and clone
        Node* cloneNode = cloneHead;
        
        //iterate both the LL's
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;          //save the pointer to 2nd node of original LL (As hume original ll ke baki nodes ka track chahiye)
            originalNode -> next = cloneNode;           //change the next of original LL and point it to clone(initially 1st node ka change hoga and it will point to 1st node of clone and then baki sare nodes ka hoga)
            originalNode = next;                        //original node ko aage badhao(forward) 
            
            //change pointer of clone LL node
            next = cloneNode -> next;               //save the pointer to 2nd node of clone LL (As hume clone ll ke baki nodes ka track chahiye)   
            cloneNode -> next = originalNode;        // clone node ke next ko point karwao original Node se(i.e original ka 2nd node as orginal Node ko aage badha diya h) // refer diagram lec 52
            cloneNode = next;           //move forard
        }
        
        //step 3: assignment of random pointer
        temp = head;            //temp pointer at head
        //iterate the LL
        while(temp != NULL) {
            if(temp -> next != NULL) {          //agar temp ka next NULL nahi h(to check for last node of LL) then......
                // ternary operator instead of iflelse
                temp -> next -> arb = temp -> arb ? temp -> arb -> next : temp -> arb;          // temp ke next ka random (i.e temp ka next hai clone node ,uska random (i.e cloneNode ka random)) == temp ka random exists karta hai(matlab NULL nahi hai) toh/then temp ka random ka next(i.e temp ka random matlab koi ek node , uss node ka next (as we have assigned orignalNode to cloneNode) (matlab agar '1' ka rondom point kar rha hai 4(original LL) ko toh 4(original LL) ka next i.e 4(clone LL) ))
            }
            temp = temp -> next -> next;        //move forward
        }
        
        //step 4 : revert the changes (bring back the positions(next pointers) of original and clone LL back to previous(original) state)
        originalNode = head;
        cloneNode = cloneHead;          //re assign the respective heads
        
        //iterate both the LL's
        while(originalNode != NULL && cloneNode != NULL) {
            originalNode -> next = cloneNode -> next;           //change original LL ke links
            originalNode = originalNode -> next;                //aage badhao
            
            if(originalNode != NULL) {
                cloneNode -> next = originalNode -> next;           //change clone LL ke links
            }
            cloneNode = cloneNode -> next;          //age badho
        }
        return cloneHead;
    }

};



int main() {

return 0;
}