#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//Binary search on an unsorted 2D array
//given an 5*5 array => [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
//  [1,4,7,11,15,
//   2,5,8,12,19,
//   3,6,9,16,22,
//   10,13,14,17,24,
//   18,21,23,26,30]
//here its not linearly sorted but elems particular in rows & cols are sorted
// start iterating rows from start(i.e 0) and columns from behind (i.e col - 1 (eg. 4))
//get the element by row index and column index // i.e row = 0 and col = 4 //i.e '15' //if elem == target => DONE 
// elem < target then  => move row forward // bcz your are at last index of the row and row is sorted, so everything behind that element is smaller , so no need of checking those elems //hence move row forward (eg . 15 < 16 , row++ i.e now row = '1')
// elem > target then  => move col behind // bcz bcz if elem is greater , there is possibility of the target existing in that row , so col-- (eg. 19 > 16 i.e col--) // now col = 3 and row = 1 i.e (elem = 12)  // 12 < 16 (row++), i.e row = 2 col = 3 (i.e elem = 16) => FOUND // DONE
//continue process for find elems



 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        
        int rowIndex = 0;   //start from first row
        int colIndex = col - 1;  //start from last column
        
        //iterate rows forward and columns backward
        while (rowIndex < row && colIndex >= 0) {
            int element = matrix[rowIndex][colIndex];       //first row and last column
            if (element == target) {
                return 1;
            }
            // forward the row when elem greater than target 
            else if (element < target) {
                rowIndex++;
            }
            //backward the col when elem less than target
            else {
                colIndex--;
            }
        }
        return 0;
}

int main(){

    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 16;

    if(searchMatrix(matrix, target)) {
        cout<<"elem found"<<endl;
    } else {
        cout<<"elem not found"<<endl;
    }

return 0;
}