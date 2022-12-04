#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// Problem => You are given K-lists (i.e 2D array | K-arrays in an array) // You need find a minimum length of range such that at least one element from each list must be included in that range
// Find a minimum/shortest range where atleast 1 element is included from the list // eg. If we have 3 lists [1,10,11] [2,3,20] [5,6,12] -> then [1,5] is the range that is minimum/shortest where atleast 1 elem is included from the list // In [1,5] -> '1' is included frm 1st list, '2' from 2nd list & '5' from 3rd list
// Elems in list are in sorted manner

// Approach => Create a min heap & insert all the starting/first elem from each list | As they are sorted min value will be inserted hence minHeap | out of all the k-elems inserted , store value of min & max elem from those inserted
// push the starting elems of k-list in form of Nodes(Nodes will have elem data, row & col position in 2D array) //assign range value start = min & end = max //
//  as its minHeap , fetch minimum val from the top // update the min. value from exsiting min val & min val fetched from minHeap top // pop the min value // update the range , check if max elem - min elem is less than end - start , check for all elem in array and keep storing the shortest/minimum range.....
// ....using end & start // check for the other elems, keep updating maxi value , push the elems in the minHeap, again extract min value from heap , check range , update if shorttest/minimum // keep doing till heap is empty & later return the shortest range by (end-start+1)


//custom Node to insert in minHeap // which shall have array's element data nd row & col position in 2D array
class Node {
    public:
        int data;
        int row;
        int col;
    
    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// custom compare operator for minHeap
class compare {
    public:
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int maxi = INT_MIN; int mini = INT_MAX;         // initialize min & max value
    priority_queue<Node*, vector<Node*>, compare > minHeap;             
    
    //1. create min heap for starting elem of each list & track mini/maxi values
    for(int i = 0; i < k; i++) {
        int element = a[i][0];          // start elem
        mini = min(mini, element);          // store maxi & mini value from start elems inserted
        maxi = max(maxi, element);
        minHeap.push(new Node(element,i,0));          // push node in minHeap with elem data & row & col position
    }   
    
    // initialize range
    int start = mini, end = maxi;
    
    //process ranges
    while(!minHeap.empty()) {
        // get mini elem from minHeap and pop it
        Node* temp = minHeap.top();
        minHeap.pop();
        
        // update mini data
        mini = temp->data;

        //range updation // if short range found within mini & maxi then update range -> start & end
        if(maxi-mini < end-start) {
            start = mini;
            end = maxi;
        }
        
        //if next elem exists in array
        if(temp->col+1 < n) {
            maxi = max(maxi, a[temp->row][temp->col + 1]);          // update max value by checking with existinf max value & next elem
            minHeap.push(new Node(a[temp->row][temp->col+1], temp -> row, temp->col+1));            // push next elem in form of Node
        }
        //next elem doesnt exists
        else {
            break;
        }
    }
    // return shortest range 
    return (end - start + 1);
}

int main() {

return 0;
}