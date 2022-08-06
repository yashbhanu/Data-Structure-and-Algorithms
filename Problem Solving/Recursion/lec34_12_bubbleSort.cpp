#include <iostream>
using namespace std;

//bubble sort means putting the largest element at the end/right most part
//calling the func again by reducing array size by '1' from behind/end as the largest elem has been placed at the end/right most part 

void sortArray(int *arr, int n) {

    //base case - already sorted OR it after whole array is iterated and sorting is complete
    if(n == 0 || n == 1) return ;

    //first case solved - largest element placed at end/right most part
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    //recursive call
    sortArray(arr, n-1);
    
}
 
int main(){

    int arr[5] = {3,1,9,2,5};

    sortArray(arr, 5);

    //print sorted array
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    } cout << endl;
    
return 0;
}