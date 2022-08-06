#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//sort 0s and 1s 
// you are given an array => [1,1,0,0,0,0,1,0] => sort it into 0's and 1 => [0 0 0 0 0 1 1 1]
//initialize left = 0 (i.e start of array) and right = n(size) - 1 (i.e end of the array)
//while left < right iterate the array if (left = start = 0) then let it be and move further left++;
//while left < right iterate the array if (right = end = 1) then let it be and move backward right--;
//while left < right and and && left(start) = 1 and right(end) = 0, now SWAPPP it   
//continue till left exceeds right


void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortOne(int arr[], int n) {
    int left = 0; int right = n - 1;

    while (left < right) {

        while(arr[left] == 0 && left < right) {
            left++;
        }
        while(arr[right] == 1 && left < right) {
            right--;
        }

        //agar yaha tk pohoch gaye iska matlab
        //arr[left] == 1 and arr[right] == 0
        if(arr[left] == 1 && arr[right] == 0 && left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main(){

    int arr[8] = {1,1,0,0,0,0,1,0};

    sortOne(arr, 8);
    printArray(arr, 8);

return 0;
}