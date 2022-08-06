#include <iostream>
using namespace std;
#include<bits/stdc++.h>



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

//remove duplicated in unsorted LL => given LL = 1->4->2->4 => after removal => 1->4->2
//create a map(key - value pairs) and  store the node->data which is visited

Node *removeDuplicates(Node *head)
{
    Node* curr = head;      //place curr on head
    Node* prev = NULL;      //place prev
    
     unordered_map<int, int> visited;       //create a map
     //iterate till curr is NULL
     while(curr != NULL) {
        //if curr node ka data visited map m exist NAHI karta then...
         if(!visited[curr -> data]) {
             visited[curr -> data] = 1;     //curr ke data ko kardo 1 (i.e visited)
             prev = curr;                   //prev ko aage badhao
             curr = curr -> next;           //curr ko aage badhao
         }
         else {         //curr node ka data visited m exist karta hai
             prev -> next = curr -> next;           //prev ka next point karwao curr ke next ko
             delete curr;                           //curr (i.e repeated node's value) ko delete kardo
         }
         curr = prev -> next;               //curr ko aage badhao
     }
    return head;
}

int main(){

return 0;
}