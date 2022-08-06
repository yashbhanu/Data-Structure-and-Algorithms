#include <iostream>
using namespace std;
#include <bits/stdc++.h>


//Rat in a Maze
//You are given a maze i.e 2D array => m[][] = {{1, 0, 0, 0},
//                                              {1, 1, 0, 1}, 
//                                              {1, 1, 0, 0},
//                                              {0, 1, 1, 1}}
//you can only walk on '1's and not on '0's  // you are initially at first position [0][0] // you need to find all possible paths to last element [3][3] by going through 1
//The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).  // you need to find the path and return directions eg. "DDDRLUD"
//first create an array 'ans' where you'll store thee path //incase the first position at which rat is standing is '0', return empty array // create srcx, srcy => initial position [0][0]
// create a visited 2D array same as 'm' // we'll check whether the element in the main arr is visited or not (if not checked that visited or not, then it'll run into infinite loop) // created a 2D array same as 'm' and initialized all values by 0 // if particular elem visited then mark it '1'  // 1 => visited , 0 => not visited => in visited arr
//create a string path  where you'll push back the directions // call the func solve() for initial position 
//base case => if x && y == n-1 (i.e last elem of array), that means path has been generated, store the answer and return // mark  elem as visited
//now we have 4 options D,l,R,U // formulaes for foll => D = (x+1,y), L = (x,y--1), R = (x,y+1), U = (x-1,y)  // here up down right left means going through an 2D array // x = rows, y = col // check the diection moves visuallizing in 2D arr
//for every  D,l,R,U we call solve func with their respective x,y (i.e directions/moves) // first we'll check if going in a particular direction (D,l,R,U) is possible or not => for that we'll use isSafe func()
//isSafe func() will check that x, y are inside the matrix && that the next direction/move is visited or not (i.e 1 OR 0) in visited arr && and its a movable path i.e '1' in main arr (1 = walkable, 0 = unwalkable)
//if isSafe return true then rat moves in that direction (i.e visited becomes True(i.e 1 in visited arr) and that particular direction D,l,R,U is pushed back in 'path')  
// then we call the solve() again for that particular position and check the next direction/move with recursion // and we track the path with recursion //as soon as rat reaches [3][3] => base case breached and path is pushed in ans
//one more thing => backtracking => while returning from functions we must pop_back the path(i.e D,l,R,U) from string and && make visited = False (i.e 0 in visited array)  
//backtracking is done so everything is removed and the program can find alternative path(i.e path 2) towards last elem [n-1][n-1]
//dry run and watch recursion tree on video (lec 40) to understand deeply


int main() {


 // } Driver Code Ends
// User function template for C++

class Solution{
    private: 
        bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m) {
            if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1) {
                return true;
            }
            else {
                return false;
            }
        }
    
        void solve(vector<vector<int>> &m,int n,vector<string>& ans, int x, int y, vector<vector<int>> visited, string path) {
            
            //base case
            if(x == n-1 && y == n-1) {
                ans.push_back(path);
                return ;
            }
            
            visited[x][y] = 1;      //first elem marked as visited
            
            //four choices - D,L,R,U
            
            //down
            int newx = x+1;
            int newy = y;
            if(isSafe(newx, newy,n, visited, m)) {
                path.push_back('D');
                solve(m, n, ans, newx, newy, visited, path);
                path.pop_back();            //backtrack
            }
            
            //left
            newx = x;
            newy = y-1;
            if(isSafe(newx, newy,n, visited, m)) {
                path.push_back('L');
                solve(m, n, ans, newx, newy, visited, path);
                path.pop_back();            //backtrack
            }
            
            //right
            newx = x;
            newy = y+1;
            if(isSafe(newx, newy,n, visited, m)) {
                path.push_back('R');
                solve(m, n, ans, newx, newy, visited, path);
                path.pop_back();                //backtrack
            }
            
            //up
            newx = x-1;
            newy = y;
            if(isSafe(newx, newy,n, visited, m)) {
                path.push_back('U');
                solve(m, n, ans, newx, newy, visited, path);
                path.pop_back();        //backtrack
            }
            
            visited[x][y] = 0;      //backtrack
        }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {

        vector<string> ans;
        
        if(m[0][0] == 0) {
            return ans;
        }
        
        int srcx = 0;
        int srcy = 0;
        
        vector<vector<int>> visited = m;    //craete a 2D array same as m
        //initialize with 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
        
        string path = "";       //path of string (eg DDRDD)
        
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());       // lexicographically increasing order
        return ans;
    }
};

return 0;
}