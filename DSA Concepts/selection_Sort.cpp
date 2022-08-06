#include <iostream>
using namespace std;
#include<vector>

//selectionSort (refer book)
//select a element from array(eg firstElem) and swap it from the minimum elem from the array
//iterate the array from (0-n-1) i.e[3,6,2,7] in first loop //set the min value = firstElem (eg 3)
//run another for loop //iterate array from (i+1 - n) i.e[6,2,7,1] //check if any value in 2nd loop is less than arr[i] i.e 3 (firstelem) //if True swap it (i.e push min. element towards right)
//keep doing till second last elem arr[i] i.e 7 //you will get sorted array


int selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n-1; i++)
    {
        int midIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[midIndex]) {
                midIndex = j;
            }
        }
        swap(arr[midIndex], arr[i]);
    }
    // return arr;
}

int main(){

    vector<int> arr = {3,6,2,7,1};
    int n = 5;
    // int sortArr = selectionSort(arr, n);

    cout<<"Sorted array is "<<selectionSort(arr,n);

return 0;
}