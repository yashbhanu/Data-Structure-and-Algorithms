#include <iostream>
using namespace std;
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


// find middle node of the linked List 
//approach =>  iterate and get length of the linkedlist  // divide length by 2 => get ans// iterate till ans and print middle node
int getLength(Node* head) {
    
    int length = 0;         //counter // iterate till last node and get length 
    while(head != NULL) {
        length++;
        head = head -> next;
    }
    return length;
}


//approach 1
Node *findMiddle(Node *head) {
    // Write your code here
    int len = getLength(head);      //get length
    int ans = len/2;                //divide length by 2 to find mid position
    
    Node* temp = head;          // pointer temp pointing to head(i.e first node)
    int cnt = 0;                // counter
    //iterate till ans(i.e mid position) // as you reach till mid position ,, keep updating temp and as you exit loop , temp will be on mid position // hence return temp
    while(cnt < ans) {
        temp = temp -> next;
        cnt++;
    }
    
    return temp;
}


//approach 2 => 2 pointers slow, fast where fast moves 2 steps and slow moves 1 step // so when fast completes n steps(eg 6), slow completes n/2 steps (eg. 3) // so slow will on get the middle node
Node* getMiddle(Node* head) {
    //empty list or single node
    if(head == NULL || head -> next == NULL) {
        return head;
    }   
    
    //2 nodes
    if(head -> next -> next == NULL) {
        return head -> next;
    }
    
    //more than 2 nodes
    Node* slow = head;                  //slow points to head(first node)
    Node* fast = head -> next;          // fast  points to second node
    
    //iterate till fast reaches null
    while(fast != NULL) {
        //fast ko 2 kadam aage badhao
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        
        //slow ko ek kadam
        slow = slow -> next;
    }
    //loop k bahar aane k bad fast->NULl hoga and slow-> mid node // hence return slow
    return slow;
}
int main(){

return 0;
}