#include <iostream>
using namespace std;

class LinkedListNode
    {
    public:
        int data;
        LinkedListNode *next;
        LinkedListNode(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

// a LL is "2->4->5->6->NULL" like this // in this approach of reversing , we'll change the pointers of every nodes and point them towards previous nodes // => "NULl<-2<-4<-5<-6" and then iterate from behind
LinkedListNode *reverseLinkedList(LinkedListNode *head) 
{
    // Write your code here
    
    //empty LL or single node
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    else {
        
        LinkedListNode* curr = head;        //create curr which points to head
        LinkedListNode* prev = NULL;        //create prev which poiints to previous of curr (initially NULL)
        LinkedListNode* forward = NULL;     //as we shall be changing "curr -> next" // but hame "curr -> next" ki change karne k bad wapis jarurat padegi // isliye humm use forward m save karlenge(as backup) 
        
        //iterate till last node
        while(curr != NULL) {
            forward = curr -> next;     //save "curr -> next" in forward
            curr -> next = prev;        // change "curr -> next" towards prev (previous node)
            prev = curr;                // update prev (move forward i.e prev+1)
            curr = forward;             // update curr // as "curr -> next" is changed // but we saved it in forward
        }
        return prev;            // prev is now pointing to last element and curr pointing to NULL // so our updated head = prev ,, from where we'll iterate the LL // hence return prev
    }
}


int main(){

return 0;
}