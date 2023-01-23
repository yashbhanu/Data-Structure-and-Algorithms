#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//Problem => You are given a sudoku to solve (i.e 9*9 matrix) // in a soduko , there are a lot on empty spaces , you need to fill it (ie solve it)
// I/P  3 0 6 5 0 8 4 0 0
//      5 2 0 0 0 0 0 0 0
//      0 8 7 0 0 0 0 3 1
//      0 0 3 0 1 0 0 8 0
//      9 0 0 8 6 3 0 0 5
//      0 5 0 0 9 0 6 0 0
//      1 3 0 0 0 0 2 5 0
//      0 0 0 0 0 0 0 7 4
//      0 0 5 2 0 6 3 0 0

// 0 Represents all the empty spaces which you need to fill correctly
// OP   3 1 6 5 7 8 4 9 2
//      5 2 9 1 3 4 7 6 8
//      4 8 7 6 2 9 5 3 1
//      2 6 3 4 1 5 9 8 7
//      9 7 4 8 6 3 1 2 5
//      8 5 1 7 9 2 6 4 3
//      1 3 8 9 4 7 2 5 6
//      6 9 2 3 5 1 8 7 4
//      7 4 5 2 8 6 3 1 9

// Approach => loop over the whole 9*9 matrix and check for empty spaces (i.e 0) // if any empty space is found then, run a loop from 1-9
// check whether placing a number from 1-9 is appropriate at this position that it satisfies all conditions (i.e 1. same no. should not there in row 2. same no. should not there in col 3. same no. should not there in 3*3 matrix)
// check for no. 1 that if it satisfies all cond -> check for no. 2 for the same...till -> if any no. can be placed at that particular position then place it and using Recursion, solve for remaining empty spaces 
// if any particular number is not safe to place (i.e doesnt satisfy cond.s), then return false ans Backtrack the previous solution (i.e prev no.) & mark it again as 0 and continue the for loop checking for other numbers if they are safe to place

//https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919
// dry run to understand better


// check if the number is safe to place on that position means satisfies all conditions (i.e 1. same no. should not there in row 2. same no. should not there in col 3. same no. should not there in 3*3 matrix)
bool isSafe(int row, int col , vector<vector<int>>& board, int val) {

    // loop over till (i.e for row, col , 3*3 matrix)
    for(int i = 0; i < board.size(); i++) {
        //row check
        if(board[row][i] == val) {          // if same val encountered in row, col or 3*3 matrix then return false
            return false;
        }
        //col check
        if(board[i][col] == val) {
            return false;
        }

        //3*3 matrix check // formula to check for3*3 matrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
            return false;
        }
    }
    // else return true if no same val is encountered
    return true;
}


bool solve(vector<vector<int>>& board) {

    int n = board[0].size();            // n (i.e 9) ....to loop over matrix, row, col

    // loop over the entire matrix
    for(int row = 0; row < n; row++) {  
        for(int col = 0; col < n; col++) {

            //if cell empty // i.e 0
            if(board[row][col] == 0) {
                // try placing each no. from 1-9 in that empty space
                for(int val = 1; val <= 9; val++) {
                    // check whether that particular no. is safe to place on that specific position (i.e satisfies all cond.s)
                    if(isSafe(row, col , board, val)) {
                        board[row][col] = val;      // if safe then place the no.(i.e val) on that position

                        //Recursive call
                        bool nextSolution = solve(board);       // now after placing the no. , using Recursion, solve(fill) for remaining empty spaces 
                        if(nextSolution)                        // if the next position pe number place krna safe h then return true (dry run)
                            return true;
                        // if the next position pe number place krna safe nhi h then return backtrack and number ko wapis prev val pe(i.e 0) pe lao (dry run)
                        else {
                        //backtrack
                        board[row][col] = 0;
                        }
                    }
                }
                return false;           // return false if no solution is found after trying all no.s from 1-9
            }
        }
    }
    return true;            // return true in the end if whole matrix is solved
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);      // pass sudoku 9*9 matrix to func. which shall return true or false
}

int main() {

return 0;
}