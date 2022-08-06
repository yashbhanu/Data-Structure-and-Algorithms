#include <iostream>
using namespace std;

// IMP NOTE
// 1. Static memory allocation => memory is allocated in stack , and memory is automatically released by stack
// 2. Dynamic memory allocation => memory is alloacted in heap, but memory isn't atutomatically released by heap, it should by released manually, how ? => 'delete' keyword
// 'delete' => releases memory from heap // delete i; => for int,char... // delete [] arr; => for arrays


int getSum(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];    //arr[i] = *(arr + i)  
    }
    return sum;
}

int main () {
/*
    int n;
    cin >> n;       //took input from user

    // int *arr = new int[5];  //created an array of size 5

    // 'new int[n]' will allocate a block of memory ,of size 'n' in heap // '*arr' is a pointer which will point to the address of first block of array
    int *arr = new int[n];      //created an array of size n during runtime (i.e dynamic)

    //taking input in array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];    //arr[i] = *(arr + i)  
    }

    int ans = getSum(arr, n);

    cout << "sum is "<< ans <<endl;
*/


    //2D Arrays
    int row;
    int col;

    cin>>row>>col;

    //creating 2D array
    int** arr = new int*[row];      //creating rows as per user input
    for(int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }

    //taking input
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
        cin >> arr[i][j];       //inputting arrays for every row created in line 46
        }
    }

    //printing output
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
        cout << arr[i][j]<<" ";     
        } cout<<endl;
    }

    //releasing memory
    for(int i = 0; i < row; i++) {
        delete [] arr[i];       //deleting arrays for every row created in line 46
    }

    delete []arr;       //deleting rows created in line 46

return 0;    
}