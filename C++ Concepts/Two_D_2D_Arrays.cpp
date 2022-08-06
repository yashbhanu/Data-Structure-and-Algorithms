#include <iostream>
using namespace std;
 
//in 2d arrays while passing 2d array in function arg, you must specify atleast the column size or it would throw error //google => why to pass column size? 
bool isPresent (int arr[][4], int target) {
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (arr[row][col] == target) {
                return 1;
            }
        }
    }
    return 0;
    
}


int main(){

    //create 2d array
    int arr[3][4];

    //hardcoded
    // int arr[3][3] = {1,2,3,4,5,6,7,8,9};

    //also
    // int arr[3][4] = {{1,11,111,111}, {2,22,222,2222}, {3,33,333,3333}};


/*
    //for taking input -> row wise
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
*/

    //for taking input -> col wise
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            cin >> arr[row][col];
        }
    }

    //print
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }
    
    
    //linear search on 2d arrays
    int target;
    cout<<"Enter target element to searched ";
    cin >> target;

    if(isPresent(arr, target)) {
        cout<<"Element found ";
    } else {
        cout<<"Element not found";
    }

return 0;
}