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

//recursion
void reverse(LinkedListNode* &head, LinkedListNode *curr, LinkedListNode* prev) {
    //base case // if curr reaches NUll (i.e last elem ke aage) // that means our prev is pointing at last element (as we would be iterating from behind, last elem would be our head) // hence head = prev // and return
    if(curr = NULL) {
        head = prev;
        return;
    }
    //els //as we shall be changing "curr -> next" and moving to next node // but hame "curr -> next" ki change karne k bad wapis jarurat padegi // isliye humm use forward m save karlenge(as backup) 
        LinkedListNode* forward = curr -> next;
        reverse(head, forward, curr);       // call reverse(pass head , next node(i.e curr -> next = forward) , update prev+1 => i.e curr)
        curr -> next = prev;        // point curr node ka next behind(i.e previous node) 
}

LinkedListNode *reverseLinkedList(LinkedListNode *head) 
{
    //created current previous and called reverse
    LinkedListNode* curr = head;
    LinkedListNode* prev = NULL;
    reverse(head, curr, prev);
    return head;
}
 
int main(){

return 0;
}