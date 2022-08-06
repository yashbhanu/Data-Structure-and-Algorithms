#include <iostream>
using namespace std;

int sumOfArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];      //keep on adding the array iterated , in the sum
    }
    return sum;
    
}


int main(){
    int size;
    cout<< "Enter the size of the array"<<endl;
    cin>>size;

    int arr[100];

    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    cout<<"The sum of array is " << sumOfArray(arr, size) <<endl;
    
return 0;
}