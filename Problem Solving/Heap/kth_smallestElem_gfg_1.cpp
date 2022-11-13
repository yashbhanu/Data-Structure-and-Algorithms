#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Problem => Given an array, find the kth smallest element in the array using heaps // eg. [23,5,7,1,6] & k = 3 -> 3rd smallest elem in array is ans = 6
// find kth smallest elem in array using max heap // find kth largest elem in array using min heap

// Approach => step 1 : create a max heap and push 1st k elems in the array in the max heap (eg. arr = [23,5,7,1,6] & k=3 , push [23,5,7] in heap)
// step 2 : for remaining elems of array , check if the elem is small than heap's top elem -> if YES then pop the top elem and push the elem of the array , such a way the smallest elem will be inserted and large elems will be popped out
// step 3 : now all k small elems have been pushed into the heap, as its a max heap the largest elem(i.e kth small elem) will be on top, return it as ans
// dry run to understand better

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> pq;
        
        //step 1    // push k elems from array into heap
        for(int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        
        //step 2    // for remaining elems, check if its small if Yes, then pop the top elem and push the small elem
        for(int i = k; i <= r; i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //step 3 // return heap's top elem(i.e kth small elem)
        int ans = pq.top();
        return ans;
    }
};

int main() {
    
return 0;
}