#include <iostream>
using namespace std;

    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };


//remove duplicated in sorted LL => given LL = 1->2->2->3 => after removal => 1->2->3
//put a current pointer on head node // iterate curr till last elem(i.e till NULL) // if(curr ka next node NULL nahi hai toh && curr ka data === curr ke next node ka data)....
//....then curr ke next node(i.e same/repeated value) ko delete kardo && curr ke next ko point karwao curr ke next ke next ko()


Node * uniqueSortedList(Node * head) {
    //empty list
    if(head == NULL) {
        return NULL;
    }
    
    //non-empty list
    Node* curr = head;
    while(curr != NULL) {
        if ((curr -> next != NULL) && curr -> data == curr -> next -> data) {
            Node* next_next = curr -> next -> next;     //curr ke next ke next node pe pointer
            Node* nodeToDelete = curr -> next;          //curr ka next (jo delete karna h)
            delete(nodeToDelete);                       //delete kardo
            curr -> next = next_next;                   //urr ke next ko point karwao curr ke next ke next ko
        }
        else {      // no repeated value
            curr = curr -> next;        //curr ko aage badha do
        }
    }
    return head;
}
 
int main(){

return 0;
}