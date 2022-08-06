#include <iostream>
using namespace std;

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

//merge 2 sorted arrays // 1 -> 3 -> 5 // 2 -> 4 -> 6 // O/P => 1 -> 2 -> 3 -> 4 -> 5 -> 6 ->
//approach => first check which LL's first elem is smaller // the LL with smallest head elem/node shall be first and other LL would be second
//iterate both the LL // and check if second LL's first node data can fit into first LL's first and second node data // i.e (curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)
// if its smaller then fit that node/elem(i.e 2nd LL node between first LL node)
//update the pointers



Node<int>* solve(Node<int>* first, Node<int>* second) {
    
    //if first list have only one node, then point first's next to entire second LL
    if(first -> next == NULL) {
        first -> next = second;
        return first;
    }
    
    Node<int>* curr1 = first;       //first LL ke first node pe point karwao
    Node<int>* next1 = curr1 -> next;       //first LL ke second node pe point karwao
    Node<int>* curr2 = second;      //second LL ke first node pe point karwao
    Node<int>* next2 = curr2 -> next;       //second LL ke second node pe point karwao
    
    //iterate 2 LL
    while(next1 != NULL && curr2 != NULL) {
        //check if 2nd list ka node 1st list ke 2 node(eg. first and second) ke beech m aasakta h kya (by comparing values(greater and smaller))
        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)) {
            //add node in between 1st and 2nd node of first LL
            curr1 -> next = curr2;      //curr2 (2nd LL ka node)
            next2 = curr2 -> next;      //next2(2nd LL ke curr node ke aage ka node)
            curr2 -> next = next1;      //curr2(which is being placed in bw 2 nodes of first LL) ko point karwao next2(first LL ke curr node ke aage ka node)
            
            //updating
            curr1 = curr2;      //curr1 ko aage badhao
            curr2 = next2;      //curr2 ko aage badhao
        }
        else {      //if elem doesnt fit bw two nodes of first LL (not greater & not smaller)
            //go one step ahead in first LL (aage badha do)
            curr1 = next1;
            next1 = next1 -> next;
            
            //if next1 become NULL then, curr1(i.e at present last node of first LL) ke peeche laaga do 2nd LL ke bache hue sare nodes/elems
            if(next1 == NULL) {
                curr1 -> next = curr2;
                return first;       //return first(pointer pointing to 1st node of list)
            }
        }
    }
    return first;           //return first(pointer pointing to 1st node of list)
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{   
    //NULL case (empty list case)
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    
    //check kis list ka pehla elem/node ka data smallest h
    if(first -> data <= second -> data) {
        return solve(first,second);     //if first ka small h then send first list as 1st and 2nd as 2nd
    }
    else {
        return solve(second,first);     //if second ka small h then send first list as 2nd and 2nd list as 1st
    }
}


int main(){

return 0;
}