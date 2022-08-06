#include <iostream>
using namespace std;
 
//minimum
int getMin(int num[], int size) {
    int minimum = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        minimum = min(minimum, num[i]);     //inbuilt function

        //same logic as above but custom
        // if(num[i] < minimum) {
        //     minimum = num[i];
        // }
    }
    return minimum;
    
}


//maximum
int getMax(int num[], int size) {
    int maximum = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        maximum = max(maximum, num[i]);     //inbuilt function

        //same logic as above but custom
        // if(num[i] < maximum) {
        //     maximum = num[i];
        // }
    }
    return maximum;
}

int main(){
    int size;
    cin>>size;

    int arr[100];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    cout<<"Minimum is "<<getMin(arr, size)<<" ";
    cout<<"Maximum is "<<getMax(arr, size)<<" ";

return 0;
}