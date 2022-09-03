#include <iostream>
#include <queue>
using namespace std;


//Circular queue => while pushing/popping, when front/rear are at array's last elem(i.e n-1), and if there is space available in front part of the array then put front/rear at front((i.e 0th index))
// agar front/rear array ke last elem pe ho, aur array k front part m space/jagah ho toh front/rear ko daldo front m(i.e 0th index)
//refer diagram for better understanding

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;        
        arr = new int[size];        //declare array
        front = rear = -1;        //initialize front and rear as -1 initially
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){ //push
        //to check if its full
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) {
            return false;        //if full return false
        }
        else if(front == -1) {  //single elem insertion
            front = rear = 0;    //initialize 0(i.e first arr node) 
        }
        //agar rear last m ho and front m jagah khali ho toh rear ko daldo samne/front m(circular queue)
        else if(rear == size-1 && front != 0) {
            rear = 0;        //to maintain cyclic operation
        }
        else {        //normal push
            rear++;  
        }
        arr[rear] = value;     //push value
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){   //pop
        if(front == -1) {    //check if empty
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
};


int main() {

return 0;
}