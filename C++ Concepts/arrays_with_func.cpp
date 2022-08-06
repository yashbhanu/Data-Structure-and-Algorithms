#include <iostream>
using namespace std;
 
//pass the array and size as arg 
void printArray (int arr[], int size) {
    //print
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<< " ";
    }
    
}

int main(){
    
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};

    printArray(arr, 10);

return 0;
}