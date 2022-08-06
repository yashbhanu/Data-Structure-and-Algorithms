#include <iostream>
using namespace std;


//print sum row wise and col wise
//given an 2d array =[1 2 3 
//                    4 5 6
//                    7 8 9]
//find row wise sum =>OP = 6 15 24
//find col wise sum =>OP = 12 15 18


void printRowSum (int arr[][3], int row, int col) {

    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        cout<< sum << " ";
    }
}

void printColSum (int arr[][3], int row, int col) {

    for (int col = 0; col < 3; col++)
    {
        int sum = 0;
        for (int row = 0; row < 3; row++)
        {
            sum += arr[row][col];
        }
        cout<< sum << " ";
    }
}



int main(){
    
    int arr[3][3];

    //take input
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
    }

    //print array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    

    printRowSum(arr, 3, 3);
    cout<<endl;
    printColSum(arr, 3, 3);

return 0;
}