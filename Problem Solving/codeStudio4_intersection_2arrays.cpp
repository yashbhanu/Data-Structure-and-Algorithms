#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
//perform on codestudio
//find intersection i.e the common value between 2 sets i.e [1,2,5,7,8] , [2,2,4,6,9] => ans = 2
//create a vector/array // while i and j are in the range of m & n i.e (size of 2 arrays)...run the loop
// if found the similar item bw elements of 2 arrays forward i and j i.e i++ and j++
//Given :- arrays will always be sorted //if arrays are sorted and we found that 1st array's value[i] (which is being compared) is less than the 2nd array's value[j] then we dont need to compare further bcz all the other values would be greater (sorted) //hence forward i (i++)
//else keep forwarding j (j++) and continue to compare values


int main(){
    //size of the array
    int n = 5;
    int m = 5;
    int arr1[5] = {1,2,5,7,8};
    int arr2[5] = {2,2,4,6,9};
    /////////////////////
    int i = 0, j = 0;
    vector<int> ans;

    while(i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }

        else if (arr1[i] < arr2[j]) {
            i++;
        }

        else {
            j++;
        }
    }
return 0;
}