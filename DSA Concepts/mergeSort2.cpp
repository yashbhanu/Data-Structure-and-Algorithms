#include <iostream>
using namespace std;

void merge(int *arr, int s, int mid, int e) {

    int i = mid+1, temp;

    while (s <= mid && mid+1 <= e) {

        if(arr[s] <= arr[mid+1]) {
            s++;
        }
        else {
            temp = arr[mid+1];
            while(i > s) {
                arr[i] = arr[i-1];
                i--;
            }
            arr[i] = temp;
            s++; mid++;
        }
    }
}

void mergeSort(int *arr, int s, int e) {

    if(s >= e) 
        return;
    else {
        int mid = s + (e-s)/2;

        mergeSort(arr, s, mid);     //left part

        mergeSort(arr, mid + 1, e);     //right part

        merge(arr, s, mid, e);
    }
}

int main(){

    int arr[7] = {2,1,5,3,8,4,9};
    int n = 7;

    mergeSort(arr, 0 , n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   cout << endl;
    
return 0;
}