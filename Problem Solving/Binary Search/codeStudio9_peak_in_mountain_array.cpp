#include <iostream>
using namespace std;

//given an array[3,4,5,1] //if we represent it on graph , it would be like graph(refer book)
//use binary search approach//declare start and end , find mid
//here if (arr[mid] < arr[mid + 1]) i.e (its in 3,4,5 line) 1st element is smaller than the next element // then update start (when it would reach peak element i.e(5) it will stop updating) and start would be 5 (i.e s = 5)
//      else (i.e arr[mid] > arr[mid + 1] (1) || arr[mid] == arr[mid + 1] (5) ) update the end to mid [i.e either 3,4,5]
//return start i.e (s) where peak value is stored

int peakValue(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s)/2;

    while (s < e) {
        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1; 
        }
        else {
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}

int main(){
    int arr[5] = {3,4,5,6,1};

    cout<<"Peak value is at index "<<peakValue(arr, 5) <<endl;
return 0;
}