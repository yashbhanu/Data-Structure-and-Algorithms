#include <iostream>
using namespace std;

//largest row sum
//given an 2d array =[1 2 3 
//                    4 5 6
//                    7 8 9]
//find row wise sum =>OP = 6 15 24 // (6,15,24) => here max is 24 so return '24' and the index of the row i.e 2
//first find row wise sum //intitialize maxi && rowIndex // if sum is greater than maxi then save maxi and index of the row
//continue till last row till u find accurate maxi and rowIndex 



int largestRowSum(int arr[][3], int row, int col ) {

    int maxi = INT_MIN;
    int rowIndex = -1;

    //find sum of all rows
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        
        if(sum > maxi) {
            maxi = sum;
            rowIndex = row;
        }
    }

    cout<<"Max sum is "<< maxi <<endl;
    return rowIndex;
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

    int ansIndex = largestRowSum(arr, 3, 3);

    cout<<"Max row is at index "<<ansIndex<<endl;

return 0;
}