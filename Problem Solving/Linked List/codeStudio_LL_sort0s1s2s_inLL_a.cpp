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

//approach 1
//sort 0s 1s 2s in LL => 0 -> 2 -> 1 -> 2 -> 1 // OP => 0 -> 1 -> 1 -> 2 -> 2 ->
//soln => count no. of 0s and 1s and 2s in LL by traversing
//and then traverse the LL and replace the data

Node* sortList(Node *head)
{
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;
    
    Node*temp = head;
    while(temp != NULL) {
        if(temp -> data == 0) {
            countZero++;            //count 0s
        }
        else if(temp -> data == 1) {
            countOne++;             // //count 1s
        }
        else if(temp -> data == 2) {
            countTwo++;              //count 2s
        }
        temp = temp -> next;
    }
    
    temp = head;        //initialize temp back at start
    while(temp != NULL){
        if(countZero != 0) {
            temp -> data = 0;           //replace data first with 0 at start
            countZero--;
        }
        else if(countOne != 0) {
            temp -> data = 1;       //replace data first with 1 after 0
            countOne--;
        }
        else if(countTwo != 0) {
            temp -> data = 2;       //replace data first with 2 after 2
            countTwo--;
        }
        temp = temp -> next;
    }
    return head;
}



int main(){

return 0;
}