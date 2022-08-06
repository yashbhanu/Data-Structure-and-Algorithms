#include <iostream>
using namespace std;

//jagged 2d array with dynamic memory allocation
// jagged array is a 2d array in which ith row has i number of columns (1 based indexing) 

int main(){

    int row;
    cin >> row;

    int **arr = new int*[row];          //dynamic memory allocation of rows
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[i + 1];        //dynamic memory allocation of columns to its corresponding row // no. of cols = ith no. of rows
    }

    //take input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j<i+1; j++)
        {
            cin >> arr[i][j];
        }
    }

    //output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << arr[i][j]<<" ";
        } cout << endl;
    }


    //release memory
    for (int i = 0; i < row; i++)
    {
        delete [] arr[i];
    }

    delete [] arr;
    
    
    

return 0;
}