#include <iostream>
using namespace std;
 
bool isSorted(int *arr, int size) {

    //base case
    if(size == 0 || size == 1) return true;     //if size 0 or 1 then either there are only '0' or '1' elems in array i.e sorted OR whole array is iterated (i.e sorted)

    if(arr[0] > arr[1])     //first elem greater than 2nd (i.e unsorted)
        return false;
    else{
        bool remainingPart = isSorted(arr + 1, size - 1);       //iterate the remaning array
        return remainingPart;
    }
}

int main(){

    int arr[5] = {2,4,6,8,9};

    int size = 5;

    bool ans = isSorted(arr,size);

    if(ans) {
        cout << "Its sorted" << endl;
    } else {
        cout << "Its unsorted" << endl;
    }
return 0;
}