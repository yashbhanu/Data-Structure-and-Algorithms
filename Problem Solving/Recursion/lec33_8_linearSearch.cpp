#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int key) {

    //base case
    if(size == 0) return false;         //i.e array has been iterated and no elem is remaining i.e key not found hence return false

    if (arr[0] == key) return true;     //check key found or not key found or not // if found return true

    else {
        bool remainingPart = linearSearch(arr + 1,size - 1,key);        //recursive call //iterate for remaining array
        return remainingPart;
    }
}

int main(){

    int arr[5] = {2,5,7,6,8};
    int size = 5;
    int key = 9;

    int ans = linearSearch(arr,size,key);

    if(ans) {
        cout << "Present" << endl;
    } else {
        cout << "Absent" << endl;
    }
return 0;
}