#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//given => an array [0,1,0,3,12] , we need to shift all zeroes to the end => Output => [1 3 12 0 0]
//we shall shift all nonZero values to left
//nonZero = 0; i.e its pointing to 1st elem of array //iterate the array by for loop check if any value != 0 i.e [if(arr[j] != 0)]
//if True then swap j  and zero //keep swapping till whole array is iterated


void shiftZeroes (int arr[], int n) {
    int nonZero = 0;

    for(int j = 0;j<n;j++) {
        if(arr[j] != 0) {
            swap(arr[j], arr[nonZero]);
            nonZero++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){

    int arr[5] = {0,1,0,3,12};

    shiftZeroes(arr, 5);
    printArray(arr, 5);

return 0;
}