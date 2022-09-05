#include <iostream>
using namespace std;


// k Queues in a single array 
// you would be given an array of size n (Eg 8) && k = 3 // so, you have to make k(i.e 3) queues in a single array
//perform push and pop operations
//take front and rear arr of k size to indicate front and rear index of respective queues in the whole array
//take next arr of size n to indicate next freespot in array && freespot to indicate the current freespot
// reference :- https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/

class kQueue {

    public:
        int n;      //length of array
        int k;      // no. of queues in which array should be divided
        int *front;     //array of k size to indicate front index of respective queues [front index of 1st queue,front index of 2nd queue....]
        int *rear;       //array of k size to indicate rear index of respective queues [rear index of 1st queue,rear index of 2nd queue....]
        int *arr;       //array of size n
        int freespot;      //indicates the current free spot in array
        int *next;          //array of k size to indicate the next free spot eg. n=5 , suppose an empty array  [1,2,3,4,5,-1] => 0th index = 1 (i.e 0th index in next arr indicates next free spot in main arr as 1, 1st index in next arr indicates next free spot in main arr as 2)


        //constructor to initialize the array and queue initially
        kQueue(int n, int k) {
            this -> n = n;      //set array size
            this -> k = k;      //set no. of queues
            front = new int[k];
            rear = new int[k];

            //initialize front and rear array with -1 initially (bcz empty array intially)
            for (int i = 0; i < k; i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];      //next array of size n
            for (int i = 0; i < n; i++)
            {
                next[i] = i+1;      // initialize next array [1,2,3,4,5...]
            }

            next[n-1] = -1;         //last block in array doesnt point to any free spot hence -1

            arr = new int[n];

            freespot = 0;       //initiallly freeSpot would be 0th index
        }


        //push operation
        void enqueue(int data, int qn) {

            //overflow check 
            if(freespot == -1) {        //indicating last elem
                cout << "No Empty Space " << endl;
                return ;
            }

            //find first free index
            int index = freespot;       //found index where elem is to be pushed

            //update freespot
            freespot = next[index];         //update freespot by next[index] as next indicates the next freespot in arr

            //check whether its 1st elem // if yes then set the front arr
            if(front[qn-1] == -1) {
                front[qn-1] = index;        //qn-1 bcz arr starts frm 0
            }
            else {
                //link new elem to prev elem // if not first elem then, suppose arr of size 8 , pushed 1 in q1 => [1,], pushed 3 in q1 => [1,3,] , pushed 6 in q2 => [1,3,6,] (this indicates [1,3] in q1 and [6] in q2) , pushed 4 again back in q1 => [1,3,6,4,] (now we need to link 3 with 4 as the next elem of q1) 
                next[rear[qn-1]] = index;           //hence update next so that on next arr's index 1(i.e elem 3) links to index 3(i.e elem 4)
            }

            //update next
            next[index] = -1;       //assign the filled spot in next index as -1

            //update rear as new elem is pushed
            rear[qn-1] = index;

            //push element
            arr[index] = data;
        }


        //pop operation
        int dequeue(int qn) {

            //underflow (incase arr is empty)
            if(front[qn-1] == -1) {
                cout << "Queue underflow" << endl;
                return -1;
            }

            //find index on which the element will be popped
            int index = front[qn-1];

            //as its a queue, we pop from front(FIFO), so update front(i.e front ko aage badhao)
            front[qn-1] = next[index];     

            //manage freespots // update freespot
            next[index] = freespot;      // as we have popped, we have a new freespot // so update next arr that indicates the next freespot
            freespot = index;           // freespot at the index on which the element is popped
            return arr[index];          //return popped elem      
        }
};



int main() {

    kQueue q(8,3);

    q.enqueue(20,1);
    q.enqueue(10,1);
    q.enqueue(40,2);
    q.enqueue(30,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;


return 0;
}