#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Problem => Find the kth largest sum of the sub array // i.e find the sum of all the sub arrays in the array and return the kth(eg. 3rd) largest sum 
// Approach -> Brute force -> run two for loops and find out the sum for all sub arrays and keep pushing that sum into vector(arr) // then sort the vector(arr) & return the kth largest elem by subtracting k from array's size



int getKthLargest(vector<int> &arr, int k)
{    
    int n = arr.size();     
    vector<int> sumList;            // array to store the sum of subarrays
    // 1st loop
	for(int i = 0; i < n; i++) {
        int sum = 0;            // intialize sum
        // calculate sum of sub array and add it to sum & add the various sums into array
        for(int j = i; j < n; j++) {
           sum += arr[j];
           sumList.push_back(sum);
        }
    }
    //sort the array of sums
    sort(sumList.begin(), sumList.end());
    // return the kth largest elem from sorted array by subtracting k from array's size
    return sumList[sumList.size() - k];
}

int main() {

return 0;
}