#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

//approach 2
//check if linked list is palindrome => 1->2->3->3->2->1 => True // 1->2->3 => False
//first find the middle of LL // after you find the middle , reverse the rest halve of the LL and attach it to the first halve => 1->2-3->1->2->3
//now comapare the first halve with 2nd halve // if it matches the true else false

class Solution{
  public:
  Node* getMid(Node* head) {
    //use 2 pointer // fast goes 2 steps forward while slow goes 1 steps // when fast will iterate whole LL, slow shall be at mid Node
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;        //fast 2 steps
        slow = slow -> next;                //slow 1 step
    }   
    return slow;            //return slow as slow will be on mid Node
  }
  
  Node* reverse(Node* head) {
    //3 pointer curr, next & prev
      Node* curr = head;
      Node* prev = NULL;
      Node* next = NULL;
      //iterate LL by curr
      while(curr != NULL) {
          Node* next = curr -> next;
          curr -> next = prev;          //change link/direction of curr node and point it to previous(i.e reverse) 
          prev = curr;                  //update prev moving forward 1 step
          curr = next;                  //update curr moving forward 1 step
      }
      
      return prev;              //return prev as head of reversed LL
  }

    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //empty list or one node
        if(head == NULL || head -> next == NULL) {
            return true;
        }
        
        //find middle
        Node* middle = getMid(head);
        
        //reverse the last half part after getting the mid
        Node* temp = middle -> next;
        middle -> next = reverse(temp);         //attach the reverse LL to first halve
        
        //compare both haves
        Node* head1 = head;         //pointer at head of first halve of LL
        Node* head2 = middle -> next;       //pointer at head of second halve of LL
        //iterate both LL
        while(head2 != NULL) {
            //compare the data of first halve and 2nd halve // if doesn't match then false
            if(head1 -> data != head2 -> data) {
                return false;
            }
            //if it matches the move forward till whole list is iterated
            else {
                head1 = head1 -> next;
                head2 = head2 -> next;
            }
        }
        //return true(i.e LL is palindrome) if first halve matches second
        return true;
        
    }
};


int main() {

return 0;
}