#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// IMP question
// Problem => Merge K Sorted Arrays | You would be given a 2D array i.e multiple sorted arrays within a single array | you need to merge all the sorted arrays and into a single array and return that array
// Problem => Now, while iterating any 2D array , we use arr[i][j] i.e row's index and col's index | so , first create a min heap and insert all the starting elem 1st elem of all arrays | insert it in the form of nodes
// Create a Node class to create node && each node will represent the data in the array and the position of the elem in the array (i.e ith(row) & jth(col) position) // insert all start/1st elem of all arrays in the minHeap in form of nodes
// minHeap will put the smallest elem at the top (bcz dats what minHeap do) // create and ans array //as arrays are sorted , all small elems will be inserted into min heap // find the smallest elem from the top of minHeap and insert into array
// the elem inserted will be some 1st elem in any of the array // iterate that specific array and keep pushing elems of that array in minHeap in form of nodes || minHeap shall put the smallest on top || take the smallest from top and insert into ans array
// keep iterating the whole 2D array , push into minHeap , extract smallest elem and push into ans array || continue till minHeap is empty
// dry run to understand better

// node class to create nodes for array elems to be inserted in minHeap
class Node {
    public:
        int data;           // data (i.e data of array elem)
        int i;              // row th position in 2D arr of dat specific node elem
        int j;              // col th position in 2D arr of dat specific node elem
        
    // intialize the node with data & its position in 2D array
    Node(int data, int row, int col) {
        this -> data = data;
        i = row;
        j = col;
    }
};

// custom class for priority queue (i.e min heap) bcz we aren'y using int but Node* data type
class compare {
    public:
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
};

 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;          // create min heap
    
    //step 1 : insert 1st elem of all arrays
    for(int i = 0; i < k; i++) {
        Node* temp = new Node(kArrays[i][0], i, 0);             // create node for 1st elem of array with ith(row) position (1,2,3....k) and 0th col position (i.e 1st elem)
        minHeap.push(temp);                                     // push 1st elem of every array into minHeap
    }
    
    vector<int> ans;
    
    // loop till minHeap is empty
    while(!minHeap.empty()) {
        
        Node* tmp = minHeap.top();          // take smallest elem from top of min heap
        ans.push_back(tmp->data);           //push its data into array
        minHeap.pop();                      // remove that elem
        
        int i = tmp -> i;               // get that inserted elem's position in 2D arr (row and col)
        int j = tmp -> j;
        
        // iterate that inserted 1st elem array and create nodes for its elem and push into minHeap | minHeap shall bring smallest elem on top | extract from top, push into ans array | repeat till whole 2D array is itearted and minHeap is empty
        if(j + 1 < kArrays[i].size()) {
            Node* next = new Node(kArrays[i][j+1], i, j + 1);
            minHeap.push(next);
        }    
    }
    // return ans array
    return ans;  
}


int main() {

return 0;
}