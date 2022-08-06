#include <iostream>
using namespace std;
 
//swap alternate values in an array [2,1,5,6,9] = [1,2,6,5,9]
//iterate throught the whole array by for loop //check if the next element is within the range of the array i.e (if(i+1)<size) {};
//if its within the range...continue...and swap alternate values (arr[i] => current value, arr[i+1] => next element i.e alternate value)
// && and add i = i + 2 i.e i+=2 move 2 values further so it would reach the next i.e 3rd indexed value


void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] << " ";
    }
    cout<<endl;
    
} 

void swapAlternate(int arr[], int size) {
    for (int i = 0; i < size; i+=2)
    {
        if(i + 1 < size) {
            swap(arr[i], arr[i+1]);
        }
    }
    
}

int main(){

    int even[8] = {2,4,15,1,8,21,7,4};
    int odd[5] = {8,5,2,6,0};

    swapAlternate(even,8);
    printArray(even,8);
    swapAlternate(odd,5);
    printArray(odd,5);


return 0;
}