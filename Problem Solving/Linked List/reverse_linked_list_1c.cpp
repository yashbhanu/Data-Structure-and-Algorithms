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

//recursion 2
LinkedListNode* reverse1(LinkedListNode* head){
    //empty LL or single node
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    
    LinkedListNode* chotaHead = reverse1(head->next);
    
    head -> next -> next = head;
    head -> next = NULL;
    
    return chotaHead;
}


LinkedListNode *reverseLinkedList(LinkedListNode *head) 
{
    //created current previous and called reverse
    // LinkedListNode* curr = head;
    // LinkedListNode* prev = NULL;
    return reverse1(head);
}
 
int main(){

return 0;
}