#include <iostream>
using namespace std;

//search in an sorted rotated array //a array => [1,2,3,7,9] when rotated => [7,9,1,2,3] //we need to search here the key
//find pivot and apply binary search approach //refer previous programs of getPivot() and BinarySearch()
//given => an rotated sorted array => [7,9,1,2,3] //represent it in a graph (refer book)
//we need to find out on which part we need to apply binary search (i.e 1st line OR 2nd line)
//first find pivot //create a BS function
//so in main() => if (k >= arr[pivot] && k <= arr[n - 1]) i.e (if key lies in range of arr[pivot] to arr[lastElem]) then key is in 2nd line/part (i.e apply BS on 2nd line/part)
// else i.e (key doesnt lie in range of arr[pivot] to arr[lastElem]) then key is in 1st line/part (i.e apply BS on 1st line/part))



int getPivot (int arr[], int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {
        if(arr[mid] >= arr[0]) {
            s = mid + 1;
        }

        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return e;
}

int BinarySearch (int arr[], int pivot,int n, int key) {
    int start = pivot;
    int end = n - 1;

    int mid = (start + end)/2;    // | (start + (end-start)/2) |   //if value is (2^31 - 1) then it would exceed the INT_MAX //replace the formula for such test cases

    while (start <= end) {
        if(arr[mid] == key) {
            return mid;
            cout<<mid;
        }

        //go to right part
        if (key > arr[mid]) {
            start = mid + 1;
        }

        //go to left part
        else{       //key < arr[mid]
            end = mid - 1;
        }

        mid = (start + end)/2; 
            
    }
    return -1;
}

int main(){

    int arr[5] = {7,9,1,2,3};
    int k = 9;
    int n = 7; 

    int pivot = getPivot(arr, n);

    if (k >= arr[pivot] && k <= arr[n - 1]) {
        //binary search on 2nd line
        cout<<BinarySearch(arr, pivot, n - 1, k );
    }
    else {
        //binary search on 1st line
        cout<<BinarySearch(arr, 0, pivot - 1,k);
    }
return 0;
}