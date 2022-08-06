#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//subsets - solve on leetcode
// given an array - [1,2,3] => we need to find all possible subsets = [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]] => we need to output in a 2D array
//here we'll include a approach of include and exclude // in exclude we'll exclude elem and in include we'll include elem
//output = array where one elem as an array block will be stored // and in 'ans' array all output elems(i.e array blocks) will be inserted
//soln
//call the solve func with with input arr = 'nums' , 'output' arr, 'ans' arr and index
// index shall iterate the input array (1,2,3) // base case = when whole array will be iterated then return // but when whole will be iterated ? => when all output blocks are created // so push all output arr blocks into 'ans' and return
//on 1st pass base case won't be breached // index = 0 (i.e 1) for exclude => call 'solve' func by index + 1 (i.e now index = 1 (i.e 2)) = nothing included and everything excluded // for include => get elem (i.e nums[index] = '1') // push back in output // '1' included
// now using recurion call again for index = 2 (include and exclude) // we have executed one step (i.e excluded && included (1)) // recursion will handle next // just index++ to iterate whole array
//dry run OR see the diagram in video (recursion tree) to understand deeply  

void solve(vector<int> nums, int index, vector <int> output, vector<vector<int>>& ans) {
        
        //base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        
        //exclude
        solve(nums, index+1, output, ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, index+1, output, ans);
    }
 
int main(){

    vector<vector<int>> subsets(vector<int>& nums);
        
        vector <int> output;
        vector<vector<int>> ans;
        int index = 0;
        // solve(nums, index, output, ans);
        // return ans;
    

return 0;
}