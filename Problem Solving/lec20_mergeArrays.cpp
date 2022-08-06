#include <iostream>
using namespace std;

//merge 2 arrays 
// given 2 arrays {1,3,5,7,9} {2,4,6,8} // merge them in sorted order
//i = pointing to first elem of arr1 // j = pointing to 2nd elem of arr2 //ik= pointing to first elem of arr3
//while (i < n && j < m) i.e iterate both the arrays // till any one array is over //i.e even if one array gets over and other is remaning come out of the loop // the remaining elems of the array will pushed later 
//comapare values of i & j //if i is smaller then push ith value in arr3 ,i++,k++// if j is smaller then push jth value in arr3 j++,k++
//if any one array is completely iterated & the while loop is over but elems from one array are remaining then...
//add it separately in arr3


void merge(int arr1[], int n, int arr2[], int m, int arr3[]) {

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    //copy remaining elems of first array
    while (i < n) {
        arr3[k++] = arr1[i++];
    }

    //copy remaining elems of second array
    while (j < m) {
        arr3[k++] = arr2[j++];
    }
} 

void printArr(int ans[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
}


int main(){

    int arr1[5] = {1,3,5,7,9};
    int arr2[4] = {2,4,6,8};
    int arr3[9] = {0};

    merge(arr1, 5, arr2, 4, arr3);
    printArr(arr3,9);


return 0;
}