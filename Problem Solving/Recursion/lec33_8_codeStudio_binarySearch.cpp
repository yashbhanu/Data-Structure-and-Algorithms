#include <iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e, int k) {

    //base case
    //element not found
    if(s>e)
        return false;

    //get mid
    int mid = s + (e-s)/2;

    //element found
    if(arr[mid] == k)
        return true;

    // if elem is smaller then search right/larger no.s part // call the func again and pass 'start' as 'mid + 1'  
    if(arr[mid] < k) {
        return binarySearch(arr, mid + 1, e, k);
    } 
    // if elem is greater then search left/small no.s part // call the func again and pass 'end' as 'mid - 1'  
    else {
        return binarySearch(arr, s, mid - 1, k);
    }

}

int main(){

    int arr[6] = {2,4,6,12,52,58};
    int size = 6;
    int key = 42;
    int start = 0, end = 5;

    cout << "Present or not: " << binarySearch(arr,start,end,key) << endl; 
return 0;
}