#include <iostream>
using namespace std;
 
//binary Search //search the value in array (refer book)
//it should be monotonic i.e increasing or decreasing
//find the mid value //compare if it matches the key //check if the mid value is less than or more than the key //as its monotonic, if value is less(of key) cut the right part and repeat from step 1 only on left part and if value is more(of key) vice versa
//update start ,end and mid value

int BinarySearch (int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    int mid = (start + end)/2;    // | (start + (end-start)/2) |   //if value is (2^31 - 1) then it would exceed the INT_MAX //replace the formula for such test cases

    while (start <= end) {
        if(arr[mid] == key) {
            return mid;
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
     
    int oddArr[5] = {2,5,9,11,13};
    int evenArr[6] = {4,6,8,9,13,16};

    int evenIndex = BinarySearch(evenArr, 6, 4);
    cout<< "index for evenArr is " << evenIndex <<endl;

    int oddIndex = BinarySearch(oddArr, 5, 13);
    cout<< "index for oddArr is " << oddIndex <<endl;

return 0;
}