#include <iostream>
using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    } cout << endl;
    
}

int getSum(int *arr, int size) {

    print(arr,size);
    //base case
    if(size == 0) return 0;     //if 0 then 0

    if(size == 1) return arr[0];        // if '1' then its the last elem or the only elem, then return arr[0]

    int remainingPart = getSum(arr + 1, size - 1);      //call the remainingPart
    int sum = arr[0] + remainingPart;           //1st elem + remaining //
    return sum; 
}


int main(){

    int arr[5] = {2,4,5,6,7};

    int size = 5;

    int sum = getSum(arr, size);

    cout << "Sum is " << sum << endl;
return 0;
}