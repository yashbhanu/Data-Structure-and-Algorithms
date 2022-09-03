#include <iostream>
#include <queue>
using namespace std;

class Deque
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;        
        arr = new int[size];        //declare array
        front = -1;
        rear = -1;        //initialize front and rear as -1 initially
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //to check if its full
        if(isFull()) {
            return false;        //if full return false
        }
        else if(isEmpty()) {  //single elem insertion
            front = rear = 0;    //initialize 0(i.e first arr node) 
        }
        //agar rear last m ho and front m jagah khali ho toh rear ko daldo samne/front m(circular queue)
        else if(front == 0 && rear != size-1) {
            front = size-1;        //to maintain cyclic operation
        }
        else {        //normal push
            front--;  
        }
        arr[front] = x;     //push value
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        //to check if its full
        if(isFull()) {
            return false;        //if full return false
        }
        else if(isEmpty()) {  //single elem insertion
            front = rear = 0;    //initialize 0(i.e first arr node) 
        }
        //agar rear last m ho and front m jagah khali ho toh rear ko daldo samne/front m(circular queue)
        else if(rear == size-1 && front != 0) {
            rear = 0;        //to maintain cyclic operation
        }
        else {        //normal push
            rear++;  
        }
        arr[rear] = x;     //push value
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()) {    //check if empty
            return -1;
        }
        int ans = arr[front];      //fetched elem to be popped
        arr[front] = -1;        //popped elem from front
        //now adjust/initialize rear and front
        if(front == rear) {        //single element
            front = rear = -1;     //back to empty when single elem popped
        }
   //agar hum pop kr rhe h toh front aage aage jayega and agar front last m hai and queue ke front part m jagah h toh front varaible ko daldo queue k front m 
        else if(front == size-1) {        //to maintain cyclic operation
            front = 0;
        }
        else {    //normal pop
              front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()) {    //check if empty
            return -1;
        }
        int ans = arr[rear];      //fetched elem to be rear
        arr[rear] = -1;        //popped elem from rear
        //now adjust/initialize rear and front
        if(front == rear) {        //single element
            front = rear = -1;     //back to empty when single elem popped
        }
   //agar hum pop kr rhe h toh front aage aage jayega and agar front last m hai and queue ke front part m jagah h toh front varaible ko daldo queue k front m 
        else if(rear == 0) {        //to maintain cyclic operation
            rear = size-1;
        }
        else {    //normal pop
              rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
         if(isEmpty()) {
             return -1;
         }   
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()) {
             return -1;
         }   
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1) {
            return true;
        }
        else{
            return false;   
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
             return true;   
        }
        else {
         return false;   
        }
    }
};

int main() {

return 0;
}