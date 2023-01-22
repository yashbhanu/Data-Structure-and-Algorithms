#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Problem => You are given n*n matrix // you need to place the queen on every col (i.e n = 4, then place 4 queen (Each on 1 col))	// but a queen can attack another queen 
// Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
// 1. They share a row. 
// 2. They share a column. 
// 3. They share a diagonal. 

//You need to place n queens , one on each col such that no queen attack each other 
// Refer the question nd diagrams on below link
//https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// The 2D matrix consists of 0s // the location on which queen is placed is marked as 1

// Approach // create a board all mark with 0 // An ans array which shall store all the possible configurations of placing n-queens satisfying the condition
// using recursion , we shall check for each position in the matrix using rows & cols , that is it safe to keep the queen on that position so it doesnt attack other (i.e satisfies all cond.s)
// if its safe then place the queen and using recursion , check for each column and as soon as you reach the last col (i.e base case breached) , if a configuration is getting formed than save it , and then backtrack to the 1st column unmarking the queens placed(i.e 1 ko wapis 0 krdo)....
// .....and again find other configuration

// watch lec 83 and dry run to understand better


void addSolution(vector<vector<int>> &ans, vector<vector<int> > &board,
int n) {

	vector<int> temp;
	// iterate the whole 2D array and push the 0s and 1s into the array
	for(int i = 0; i < n;i++) {
		for(int j = 0; j < n; j++) {
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);			// push a particular configuration into ans
}

bool isSafe(int row , int col, vector<vector<int> > &board, int n) {

	int x = row;
	int y = col;

	//check for same row // check if any queen exists in the same row (horizontal) 
	while(y >= 0) {
		if(board[x][y] == 1) {
			return false;
		}
		y--;
	}

	x = row; 
	y = col;

	//check for diagonal // upward rightwards diagonal // if any queen exists in that path then return false
	while(x >= 0 && y >= 0) {
		if(board[x][y] == 1) {
			return false;
		}
		y--;
		x--;
	}

	x = row; 
	y = col;

	//check for diagonal // downward rightwards diagonal // if any queen exists in that path then return
	while(x < n && y >= 0) {
		if(board[x][y] == 1) {
			return false;
		}
		y--;
		x++;
	}

	return true;		// if no queen exists, on any of the paths then return true (i.e its a safe position to place the queen)

}

void solve(int col,vector<vector<int>> &ans,vector<vector<int> > &board,
int n) {

	//base case // if reached till last col (i.e a configuration is formed)
	if(col == n) {
		addSolution(ans, board, n);			// save it and return
		return;
	}

	//RECURSION (solve 1 case)		// iterate the column's row (i.e check vertically)
	for(int row = 0; row < n; row++) {
		if(isSafe(row,col, board, n)) {			// check if a particular position is safe (i.e satisfying all conditions)
			//if placing queen is safe
			board[row][col] = 1;			// place it // i.e mark as 1
			solve(col + 1,ans, board, n);			// call func. for another col
			//BACKTRACK
			board[row][col] = 0;			// unmark the queen using backtracking , to check other possible configuartions
		}
	}

}


vector<vector<int>> nQueens(int n)
{
	vector<vector<int> > board(n, vector<int>(n,0));			// our chess board initially marked as 0
	vector<vector<int>> ans;									//to store all possible configurations of placing n-queens

	solve(0,ans, board,n);

	return ans;
	
}


int main() {

return 0;
}