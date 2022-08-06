#include <iostream>
using namespace std;
#include <bits/stdc++.h>
// The sine wave for the matrix:- given array =>
// 1 2 3
// 4 5 6
// 7 8 9
//print like a wave
//OP will be [1, 4, 7, 8, 5, 2, 3, 6, 9].
// first print (1,4,7)=> top to bottom //2nd print (8,5,2)=> bottom to top //3rd print (3,6,9)=>top to bottom
//observe that when column = even index (top to bottom) //column = odd index (bottom to top)
//first iterate the columns //check if col is even or odd (if odd no. is '&' with 1 => it'll return '1' and and even is '&' then it'll return '0')
//acc. to col (even or odd) , iterate rows either top to bottom OR bottom to top and insert into vector


vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector <int> ans;
	//iterate col
	for (int col = 0; col < mCols; col++) {
		
		//if col is odd => Bottom to Top
		if(col&1) {
			for (int row = nRows - 1; row >= 0; row--) {
				ans.push_back(arr[row][col]);
			}
		}
		//if col is 0 or even => Top to Bottom
		else {
			for (int row = 0; row < nRows; row++){
				ans.push_back(arr[row][col]);
			}
		}
	}
	return ans;
}

int main(){

    vector<vector<int>> arr = {{1,2,3},{4,5,6}, {7,8,9}}; 

    wavePrint(arr, 3, 3);

return 0;
}