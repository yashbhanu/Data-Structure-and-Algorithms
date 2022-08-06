#include <iostream>
using namespace std;

//reverse in k-groups => "3->4->1->5->8->2" => consider LL , now= suppose k=2 then reverse 2 nodes => "4->3->5->1->2->8" // suppose k=3 then reverse 3 nodes => "1->4->3->2->8->5"
//approach => we'll reverse the first k nodes using iterative approach aur baki k nodes recursion sambhal lega
//base case if head = NULL then return null i.e if empty then NULL ,, and if head gets out of the LL pointing to NULL then return null
// step 1 => create pointer curr = pointing at head(first ndode), next , prev and count // iterate the LL till the first k nodes(curr != NULL && count < k) //point next(next node) to curr -> next // point curr node to previous(i.e reverse)(curr -> next = prev)  // prev, curr, count ko aage badha do
//step 2 => recursive call // we aleardy have 2 nodes reversed and now we need to reverse the remaining part and attach to the first part ,, so after we reverse first 2 nodes (3->4->) // initially head = 3 // after revrse (4->3) still head = 3 // ab hume remaining part ko reverse karke '3' k aage lagana hai // isliye (head-> next = recursive func)
//after completion of all steps prev = 4 //i.e the new head of reversed LL //hence return prev // so it'll iterate from '4' and we'll print an reverse LL

class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

Node* kReverse(Node* head, int k) {
    // base case
    if(head == NULL) {
        return NULL;
    }
    
    //step 1 => reverse first k nodes (i.e if k=2, then reverse first 2 nodes)
    Node*curr = head;
    Node*next = NULL;
    Node*prev = NULL;
    int count = 0;
    
    while(curr != NULL && count < k) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step 2 => recursive call
    if(next != NULL) {
        head -> next = kReverse(next, k);
    }
    
    return prev;

    
}

 
int main(){

return 0;
}