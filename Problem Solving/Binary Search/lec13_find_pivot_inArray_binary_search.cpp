#include <iostream>
using namespace std;

//find pivot in array i.e minimum using BinarySearch i.e in TC 0(logn)
//given an array [3,8,10,17,1,2,3] //answer/pivot element is '1'
//set start ,end and mid //if arr[mid] > arr[0] i.e mid greater than start/first elem i.e the element lies on 1st line/plane (ref book diagram) //update start (i.e now we'll now search on right part)
//else i.e arr[mid] <= arr[0] (mid lesser than end/last elem) i.e the element lies on 2nd line/plane(ref book) //update end to mid i.e if end = last elem OR pivot pt. //move end backwards OR let it remain where it is
//update mid // return s(start) OR e(end) , both points to pivot elem

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


int main(){

    int arr[7] = {3,8,10,17,1,2,3};

    cout<<"Pivot is on index "<<getPivot(arr, 7)<<endl;


return 0;
}