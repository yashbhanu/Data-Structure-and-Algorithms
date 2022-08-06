#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//rotate a given matrix 3*3 by 90 degrees
//given an 2d array =[1 2 3 
//                    4 5 6
//                    7 8 9]
//Output rotate by 90 = > [7 4 1 
//                         8 5 2
//                         9 6 3]
//observe carefully that the OP is just a reverse of [1 4 7 
//                                                    2 5 8
//                                                    3 6 9]
//so we have to change the original array by changing columns into rows and rows into columns (i.e transpose) // and then just reverse it
//for transpose we have to swap (2,4), (7,3), (8,6)
//run a for loop from (0 - n) for no. of rows
//run another for loop (0 - i) for cols
//first iteration => i = 0 , j = 0, 0 < 0 =>false
//2nd iteration => i = 1, j = 0, 0 < 1 => true // swap(matrix[1][0], matrix[0][1]) i.e  swap(matrix[4], matrix[2])
//3rd => i = 2, j = 0, 0 < 2 => True // swap(matrix[2][0], matrix[0][2]) i.e swap(matrix[7], matrix[3])   *//*  i = 2, j = 1, 1 < 2 => True // swap(matrix[2][1], matrix[1][2]) i.e swap(matrix[8], matrix[6]) 
//got the transpose
//now just reverse the rows  reverse(matrix[0].begin(), matrix[0].end()).....etc


void rotate(vector<vector<int>>& matrix) {
        
        //get transpose first (i.e change columns into rows and rows into columns)
        for (int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //now reverse
        for(int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
}
 
int main(){

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

return 0;
}