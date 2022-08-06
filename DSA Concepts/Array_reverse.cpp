#include <iostream>
using namespace std;
 
void reverse (int arr[], int n) {
    int start = 0;
    int end = n-1;      //bcz array starts with 0

    while(start <= end) {
        swap(arr[start], arr[end]);         //built in function 'swap' //give it 2 elems and it would swap it
        start++;
        end--;
    }
}

void printArray (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

int main(){

    int arr[6] = {1,2,3,4,5,6};
    int arr2[5] = {10,11,12,13,14};

    reverse(arr, 6);
    reverse(arr2, 5);

    printArray(arr, 6);
    printArray(arr2, 5);

return 0;
}