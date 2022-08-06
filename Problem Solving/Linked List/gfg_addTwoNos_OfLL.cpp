#include <iostream>
using namespace std;


struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

//given are two LL // LL1 => 2->3->4 // LL2 => 4->5 // add both the LL 234+45 = 279 // return a LL of the added valu => 2->7->9
//approach // but how will you add 2->3->4 + 4->5 as we add from right side // hence reverse both LL => 4->3->2 & 5->4 //
// after  reversing add both the LLs and keep on creating a new node every time you add 4+5 = 9(create node) , 3 + 4 = 7(create node) , 2 (create node) \
// now we have created a LL 9->7->2 // reverse it => 2->7->9 => answer // return newly created LL(i.e added values of both LL) 


class Solution
{
    private :
    Node* reverse(Node* head) {
      Node* curr = head;        //curr on head
      Node* prev = NULL;
      Node* next = NULL;
      //iterate LL and change the link/pointer and point it towards previous node
      while(curr != NULL) {
          next = curr -> next;      //save next node
          curr -> next = prev;      //point to previous node
          prev = curr;              //update prev // one step forward
          curr = next;              //update curr // one step forward
    }
      return prev;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val) {
        
        Node* temp = new Node(val);         //create new node with val passed as arg
        //empty list
        if(head == NULL) {
            head = temp;            //temp poiting to newly created // head pointing to temp (i.e new node)
            tail = temp;            // tail pointing to temp (i.e new node)
            return;
        }
        else {      //if not empty
            tail -> next = temp;        //update pointer of last node(now 2nd last) and point towards new node(now last)      
            tail = temp;                //update tail to last node(newly created)
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second) {
        int carry = 0;          //as we are adding, we want a carry to carry forward values above 10
        
        Node* ansHead = NULL;       //pointer pointing towards the head of the new LL
        Node* ansTail = NULL;        //pointer pointing towards the tail of the new LL
        
        //first is pointer pointing towards head of first LL // second is pointer pointing towards head of second LL
        //iterate both LL in below while loop and add values 
        //as one LL can be smaller than the other LL // we use OR operator // agar first NULL nahi h ya fir second NULL nahi h yah fir carry zero nhi h(for LL of eqaul lengths) tab tk loop m raho (3 mese ek bhi condition agar true rahegi toh loop chalu rahega) (eg. second NULL hogya but first nahi hua fir bhi loop chalta rahega)
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;           //val1 will be considered 0 initially // incase first LL gets empty but second LL is left , so first will be pointing to NULL , so we assign value of first LL to be '0' // so we'll add '0' + remaining value of second LL
            // if first is not pointing to NULL (i.e first LL abtk khtm nhi hui, then val1 = first jis node ko point kar rha h uss node ka data)
            if(first != NULL) {
                val1 = first -> data;
            }
            
            int val2 = 0;           //val2 will be considered 0 initially // incase second LL gets empty but first LL is left , so second will be pointing to NULL , so we assign value of second LL to be '0' // so we'll add '0' + remaining value of first LL      
            // if second is not pointing to NULL (i.e second LL abtk khtm nhi hui, then val2 = second jis node ko point kar rha h uss node ka data)
            if(second != NULL) {
                val2 = second -> data;
            }
            
            //add value val1 = 1st LL value + val2 = 2nd LL value + carry = (initially 0)  
            int sum = carry + val1 + val2;
            
            int digit = sum%10;             // after getting , we need the digit // if addition is 5+5 = 10 // we shall consider '0' as hthe digit and '1' as carry // to get digit mod by 0
            
            //create new node and into ans LL;
            insertAtTail(ansHead,ansTail,digit);            //create a new node (Eg for '0') // and keep adding new node to tail 
            
            carry = sum/10;             // get the carry which will be added in the next loop iteration // if sum=10, then 10/10 = 1 = carry 
            if(first != NULL){
                first = first -> next;          // if first not null then , first ko aage badha do
            }
            if(second != NULL){
                second = second -> next;    	     // if second not null then , second ko aage badha do
            }
        }
        return ansHead;
    }
    

    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //step 1 = reverse all LL
        first = reverse(first);         
        second = reverse(second);
        
        //step 2 = add 2 LL
        Node*ans = add(first, second);
        
        //step 3 = reverse the added LL
        ans = reverse(ans);
        
        return ans;         // return ans(pointer pointing towards head(i.e first node)of newly created LL)
    }
};


int main() {

return 0;
}