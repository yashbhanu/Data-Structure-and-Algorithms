#include <iostream>
using namespace std;

//merge sort - sort the array (refer book - diagram)
//first divide the array into smaller blocks by start, end , mid with help of recursion //the whole array will be divided into 1-1 block/array each [2], [1], [5], [3], [8] //after that s >= e becomes true and it returns
//then for every array merge operation is performed and && merging is done with sorting
//after the array is divided into 1-1 block, it returns and merging is done //for every array (i.e [2,1,5] => [2,1] => [2],[1],|| [5], || [3,8] => [3] ,[8]) which is getting halved, merge operation is called
//a array is always broken down into 2 arrs, so we copy those 2 arrs into 2 new arrays // get the length of those 2 arrs => dynamically allocate two new arrays (*first, *second) // copy values // then merge those 2 arrays into main arr
// compare values in the 2 arrays // keep placing the shorter one first in the main arr and merge two arrays in a sorted manner


void merge(int *arr, int s, int e) {
    int mid = (s+e)/2;

    int len1 = mid - s + 1;     //length of array1 after dividing it by it's mid value
    int len2 = e - mid;     //length of array2 after dividing it by it's mid value

    //dynamically allocating 2 new arrays for copying values of 'arr'
    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;     //mainArrayIndex = 'first value'
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];       //copy
    }
    
    mainArrayIndex = mid + 1;       //update mainArrayIndex to copy values into second array
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];  //copy
    }

    //merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;     //update mainArrayIndex

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {        //sort
            arr[mainArrayIndex++] = first[index1++];        //copy 
        }
        else {
            arr[mainArrayIndex++] = second[index2++];        //copy 
        }
    }

    //if arr1 is of length = 2 and arr2 is of length = 3 //so after above while loop arr2's 1 value will be remaining //so if 1 array length exceeds other => then to push it into array , we have to push it separetly
    while(index1 < len1) {
            arr[mainArrayIndex++] = first[index1++];        //copy 
    }

    while(index2 < len2) {
            arr[mainArrayIndex++] = second[index2++];        //copy 
    }

    //free up memory as we are dynamically allocating array
    delete[]first;
    delete[]second;

}

void mergeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }

    int mid = (s+e)/2;

    //breaking down left part into smaller blocks/arrays
    mergeSort(arr, s, mid);

    //breaking down right part into smaller blocks/arrays
    mergeSort(arr, mid + 1, e);


    //merge the smaller blocks/arrays in a sorted manner
    merge(arr, s, e);

}
 
int main(){

    int arr[5] = {2,1,5,3,8};
    int n = 5;

    mergeSort(arr, 0 , n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;
    
return 0;
}