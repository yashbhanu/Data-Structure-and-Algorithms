#include <iostream>
using namespace std;

// A heap is a data structure which is a Complete Binary Tree(CBT i.e all levels are completely filled except the last level && nodes are added from the left side) && a heap follows heap order property
// A heap order property contains 2 types of properties 1. Max heap : Parents node's data value is always greater than child node's data value  2. Min heap : Child node's data value is always smaller than child node's data value

//create a heap using an array
class Heap {

    public:
        int arr[100];       // array used to create heap
        int size;           // size of the array/heap

    // intialize heap
    Heap() {
        arr[0] = -1;        // we shall always start the heap from index 1 (i.e root node 1), hence array's 1st index arr[0] will have nothing (i.e -1)
        size = 0;           //inital size as 0
    }

    // function to insert a node
    void insert(int val) {
        size = size + 1;        // as we are inserting a node, increement the size by 1
        int index = size;       // size of the array will be the current index (eg. size is 2, then we have to insert element at index 2)
        arr[index] = val;       // insert value in array(i.e created a node)

        //bring the node in right position as we are following max heap property
        while(index > 1) {
            int parent = index/2;       // formula to find index of the parent node in a heap

            // max heap // if parent node's data is smaller than child node's data , then swap parent and child node
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            // inserted node is at right position (i.e smaller than parent node's data) // hence return
            else {
                return ;
            }
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        } 
        cout << endl;
    }

    // delete a node/elem from heap/array // when we delete a node in heap, the root node is deleted first
    void deleteFromHeap() {
        if(size == 0) {
            cout << "Nothing to delete" << endl;
            return ;
        }

        //step 1 : put last element into first index (i.eradicate root node and replace with last elem)
        arr[1] = arr[size];

        //step 2 : remove last element (i.e elem which is now put in root node so remove it from the last)
        size--;

        //step 3 : take root node to its correct position
        int i = 1;
        // loop till whole array/heap is checked
        while (i < size)
        {
            int leftIndex = 2*i;        // formula to find index of left child of the root node
            int rightIndex = 2*i + 1;           // formula to find index of right child of the root node

            //left // check if root node's data value is greater than child node's data value (MAX HEAP) // if NO , then swap child and parent node // && update index(i)
            if(leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            //right // check if root node's data value is greater than child node's data value (MAX HEAP) // if NO , then swap child and parent node // && update index(i)
            else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            // node is in correct position, return
            else {
                return ;
            }
        }
        
    }

};

int main() {

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();

return 0;
}