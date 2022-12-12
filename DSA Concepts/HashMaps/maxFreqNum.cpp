#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Problem -> find maximum occuring values in an array // if there are 2 or more elements of same frequency, then return the element which ocuurs in the array first i.e whose index is lowest
// eg . arr = [1,2,3,1,2] => return 1

// Approach => use a map to store count of its corresponding elems // and return the 1st elem in array which has maxFreq

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> count;           // initialize map
    
    int maxFreq = 0;            
    int maxAns = 0;
    
    //loop the array
    for(int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;        // increement the count of corresponding elem
        maxFreq = max(maxFreq, count[arr[i]]);          // store the max frequency of element in array
    }
    
    // loop over array
    for(int i = 0; i < arr.size(); i++) {
        // if max frequency matches the count of an element in the map, store that elem in maxAns and break (i.e returning 1st elem from array with max frequency)
        if(maxFreq == count[arr[i]]) {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main() {

return 0;
}