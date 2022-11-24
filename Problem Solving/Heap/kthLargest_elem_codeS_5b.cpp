#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Problem => Find the kth largest sum of the sub array // i.e find the sum of all the sub arrays in the array and return the kth(eg. 3rd) largest sum 
// Approach -> using min heap -> run two for loops and find out the sum for sub arrays and push first k elems(eg. k=3) in min heap // then after pushing k(eg. 3 elems) in min heap // compare sum with miniHeap.top() i.e smallest elem
// if sum is greater than mini.top() i.e smallest elem , pop the top elem(i.e smallest elem) and push the larger value of sum in min heap // after iterating the whole array, and comparing and pushing, mini.top() will have the 3rd largest elem // bcz of min heaps properties
// dry run to understand better


int getKthLargest(vector<int> &arr, int k)
{    
    int n = arr.size();     
    priority_queue<int , vector<int>,greater<int> > mini;
    // 1st loop
	for(int i = 0; i < n; i++) {
        int sum = 0;            // intialize sum
        // calculate sum of sub array and add it to sum
        for(int j = i; j < n; j++) {
           sum += arr[j];
           // add 1st k elems in min heap
           if(mini.size() < k) {
                mini.push(sum);
            }
            // after k elems are inserted in min heap, compare the sum with top elem, if sum is greater than remove top elem(i.e smallest elem) and push sum(i.e larger elem)
            else{
                if(sum > mini.top()) {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    //after all iteration return ans as minHeap's top elem // as only k(eg. k=3) elem will be present in minHeap and top elem will be kth largest and other two will be 1st and 2nd largest
    return mini.top();
}

int main() {

return 0;
}