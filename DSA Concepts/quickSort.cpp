#include <iostream>
using namespace std;


//quick Sort - Sorting algorithm
// partition -  place the element at right position
// every elem at its left should be smaller && every elem at its right should be greater
// continue using recursion after partition
// take an array - [2,1,5,3,8,4,9]
//first check base case // if '1' elem or '0' elem then return
// call the partition func() :- pivot = startElem (i.e 2)
// check how many elems are smaller than 1st elem (i.e 2) => '1' only
//place startEem (i.e pivot = 2) at (s + cnt) = (0 + 1) = 1th position by swapping => [1,2,5,3,8,4,9]
//now check the condition that elems on left part should be smaller and right part should be greater than pivot(i.e 2)
//condition already satisfied => return pivotIndex (i.e '1' for 2)  // suppose pivot = '8' => then put pointer i,j at start and end //iterate from i++ till pivotIndex && j-- till pivotIndex......=>
//if ith elem is smaller then i++ and jth elem is greater then j-- //but if vice versa then swap ith and jth elem => this shall make all elems smaller on left part && greater on right part of pivot 
//return pivotIndex
//quickSort called again for left and right part of '2' => partitioning for right and left part => 
//1st elem placed at right position and left and right elems smaller and greater respc. condition satisfied => using recursion => array sorted 


int partition(int *arr, int s, int e) {

    int pivot = arr[s];         //starting elem

    int cnt = 0;
    //check how many elems are smaller than 1st elem
    for(int i=s+1; i <= e; i++) {
        if(arr[i] <= pivot) {
            cnt++;
        }
    }

    //place pivot(i.e start elem) at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    

    //now check the condition that elems on left part should be smaller and right part should be greater
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e) {

    //base case
    if(s >= e) return ;

    //partition
    int p = partition(arr, s, e);

    //sort the left part
    quickSort(arr, s , p-1);

    //right part
    quickSort(arr, p + 1 , e);

}

int main(){

    int arr[7] = {2,1,5,3,8,4,9};
    int n = 7;

    quickSort(arr, 0 , n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;
    
return 0;
}