#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Problem => Merge 2 given binary Max Heaps // Given are 2 arrays (a & b -> both max heaps) -> merge them together into s single max heap

// Approach => Given are 2 arrays 1. Create an array and push all elems from other 2 arrays into this array 2. Now use heapify algo to convert a random array into a max heap

class Solution{
    
    // for 0 based indexing
    // Heapify Algoritm => A heapify algo. is to convert a given array into heap data structure // here we'll exclude leaf nodes as they already a heap by using n/2 formula // T.C O(logn)
    void heapify(vector<int> &arr, int n, int i) {
        
        int largest = i;        // i i.e current node shall be the largest
        int left = 2*i + 1;         // find current node's left & right child
        int right = 2*i + 2;
        
        //check if i(i.e current node/largest) is smaller than left child // if yes(the acc. to max heap property) , update largest to left (as left node's value is greater than ith(ie current))
        if(left < n && arr[largest] < arr[left]) {
            largest = left;
        }
        
        //check if i(i.e current node/largest) is smaller than right child // if yes(the acc. to max heap property) , update largest to right (as right node's value is greater than ith(ie current))
        if(right < n && arr[largest] < arr[right]) {
            largest = right;
        }
        
        // if largest value is updated (if its not equal to i bcz it set to i earlier) , that means we need to swap values
        if(largest != i) {
            swap(arr[largest], arr[i]);              // swap largest(right/left) with ith(current node)
            heapify(arr, n, largest);                 // use recursion to check for other nodes in the tree to create heap data structure with max heap property
        }
        
    }
    
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        
        //step 1: merge 2 arrays
        for(auto i:a)
            ans.push_back(i);
        for(auto i:b)
            ans.push_back(i);
            
        // step 2 : create a heap using merged array (heapify algo)
        int size = ans.size();

        //start with size/2 - 1 from reverse as we are excluding leaf nodes // for 0 Based indexing
        for(int i = size/2 - 1; i>=0; i--) {
            heapify(ans, size, i);
        }
        
        return ans;
        
    }
};

int main() {

return 0;
}