#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Rat in a Maze
//You are given a maze i.e 2D array => m[][] = {{1, 0, 0, 0},
//                                              {1, 1, 0, 1}, 
//                                              {1, 1, 0, 0},
//                                              {0, 1, 1, 1}}
//you can only walk on '1's and not on '0's  // you are initially at first position [0][0] // you need to find all possible paths to last element [3][3] by going through 1
//The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).  // you need to find the path and return directions eg. "DDDRLUD"
//first create an array 'ans' where you'll store the path //incase the first position at which rat is standing is '0', return empty array // create x, y => initial position [0][0]
// create a visited 2D array // we'll check whether the element in the main arr is visited or not (if not checked that visited or not, then it'll run into infinite loop) // created a 2D array visited and initialize all values by 0 // if particular elem visited then mark it '1'  // 1 => visited , 0 => not visited => in visited arr
//create a string path  where you'll push back the directions // call the func solve() for initial position 
//base case => if x == n-1 && y == n-1 (i.e last elem of array), that means destination is reached, path has been generated, store the answer and return // mark  elem as visited
//now we have 4 options D,L,R,U // formulaes for foll => D = (x+1,y), L = (x,y-1), R = (x,y+1), U = (x-1,y)  // here up down right left means going through an 2D array // x = rows, y = col // check the diection moves visualizing in 2D arr
//for every  D,L,R,U we call solve func with their respective x,y (i.e directions/moves) // first we'll check if going in a particular direction (D,L,R,U) is possible or not => for that we'll use isSafe func()
//isSafe func() will check that x, y are inside the matrix && that the next direction/move is visited or not (i.e 1 OR 0) in visited arr && and its a movable path i.e '1' in main arr (1 = walkable, 0 = unwalkable)
//if isSafe return true then rat moves in that direction (i.e visited becomes True(i.e 1 in visited arr) and that particular direction D,l,R,U is pushed back in 'path')  
// then we call the solve() again for that particular position and check the next direction/move with recursion // and we track the path with recursion //as soon as rat reaches [3][3] => base case breached and path is pushed in ans
//one more thing => backtracking => while returning from functions we must pop_back the path(i.e D,l,R,U) from string and && make visited = False (i.e 0 in visited array)  
//backtracking is done so elements are removed while returning and the program can find alternative path(i.e path 2) towards last elem [n-1][n-1]
//dry run and watch backtracking video (lec 82) to understand deeply

bool isSafe(int newx, int newy,vector< vector <bool> > &vis,
 vector < vector <int>> &arr, int n ) {

    if((newx >=0 && newx < n) && (newy >=0 && newy < n) &&
    vis[newx][newy] != 1 && arr[newx][newy] == 1) {
        return true;
    }
    else{
        return false;
    }

}


void solve(int x, int y, vector < vector <int>> &arr, int n,
vector<string> &ans, vector< vector <bool> > &vis, string path) {

    //base case
    if(x == n-1 && y == n-1) {
        ans.push_back(path);            //reached destination (i.e 3,3), so push the path(eg."DDDRDR")
        return;
    }

    //4 Movement D,L,R,U (alphabetically (i.e sorted(lexicography)))
    vis[x][y] = 1;          // mark the elem which is visited(i.e 1)
    //DOWN
    if(isSafe(x+1,y,vis, arr,n)) {
        solve(x+1, y, arr, n, ans, vis, path + 'D');        // add 'D' in the path while going down // and when program will return from this func.it shall revert back to its original path (i.e will pop_back 'D') -> Backtracking
    }

    //LEFT
    if(isSafe(x,y-1,vis, arr,n)) {
        solve(x, y-1, arr, n, ans, vis, path + 'L');
    }

    //RIGHT
    if(isSafe(x,y+1,vis, arr,n)) {
        solve(x, y+1, arr, n, ans, vis, path + 'R');
    }

    //UP
    if(isSafe(x-1,y,vis, arr,n)) {
        solve(x-1, y, arr, n, ans, vis, path + 'U');
    }

    vis[x][y] = 0;          // Backtrack (while returning from func. mark the elems as unvisited (i.e 0))

}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;

    vector< vector <bool> > visited(n, vector<bool>(n,0));      //craete a 2D array to mark the position visited or not (0 OR 1) && initialize all with 0 initially

    string path = "";

    if(arr[0][0] == 0)
        return ans;

    solve(0,0,arr, n, ans, visited,path);       //path of string (eg DDRDD)
    return ans;

}

int main() {

return 0;
}