#include <iostream>
#include <queue>
using namespace std;


//Queue implementation using classes

class Queue {
        int* arr;
        int frontt;
        int rear;
        int size;
public:
    Queue() {
        // Implement the Constructor
        size = 100001;        //set it manually as its not given 
        arr = new int[size];      //initialize array
        frontt = 0;        // initialize front (initally at 1st pos.)
        rear = 0;        // initialize rear (initally at 1st pos.)
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frontt == rear) 
            return true;
        else
            return false;
    }

    int enqueue(int data) {
        // Implement the enqueue() function //push
        if(rear == size)
            return -1;
        else
            arr[rear] = data;     //push data
            rear++;        //move forward
    }

    int dequeue() {
        // Implement the dequeue() function //pop
        if(rear == frontt)
             return -1;
        else {
             int ans = arr[frontt];    //fetch the elem to pop
             arr[frontt] = -1;        //remove elem
             frontt++;        //move forward as in a queue first elem will be removed     
            //if queue gets empty after popping , revert front & rear to OG positions
            if(frontt == rear) {
                 frontt = 0;
                 rear = 0;
            }
            return ans;
        }
            
    }

    int front() {
        // Implement the front() function
        if(frontt == rear)
            return -1;
        else {
            return arr[frontt];
        }
    }
};



int main() {

return 0;
}