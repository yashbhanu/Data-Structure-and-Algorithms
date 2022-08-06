#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//IMP question
//given a 3*3 array => [[1,2,3],[4,5,6],[7,8,9]] // we need to print the array in sprial way (for visualization refer book) exprected OP =>  [1,2,3,6,9,8,7,4,5]
 //approach => 1. first print starting row 2. print endling column 3. print ending column //4. print starting column
//the iterated columns wont be considered again and would be updated and so inner/deeper elem could be traversed
//1. get row size and col size // get total elems by row*col // set count var to track the elems traversed
//2. while count(i.e no of elems printed) is less than total(no of elems) run loop
//print starting row => iterate from startCol to endCol (0 - 2)// print (startRow) //update startRow++ (i.e now '1')
//print ending column => iterate from startRow to endRow (1 - 2) //print (endCol) //update endCol-- (i.e now '1')
//print ending row => iterate from endCol to StartCol (1 - 0) // print (endRow) //update endRow -- (i.e now '1')
//print startCol => iterate from endRow to startRow (1) // print (startCol) //update startCol++ (i.e now '1')
//continue till all elems are traversed like spiral 

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row*col;
        int count = 0;
        
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;
        
        while (count < total) {
            
            //print starting row
            
            for (int index = startingCol; count < total && index <= endingCol; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            
            //print ending column
            for(int index = startingRow; count < total && index <= endingRow; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            
            //print ending row
            for(int index = endingCol; count < total && index>=startingCol; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            
            //print starting column
            for (int index = endingRow; count < total && index>=startingRow; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
}


int main(){

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    spiralOrder(matrix);
    

return 0;
}