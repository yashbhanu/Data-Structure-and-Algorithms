#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//solve on leetcode
//given an input = [1,2,3] // find all possible permutations of the input => [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//we need to output in a 2D array hence we created a 2D array 'ans' // call the solve function ,pass args
//index is to iterate the whole array/input //base case = when whole array will be iterated then return // but when whole will be iterated ? => when all output blocks are created // so push all num array (i.e num , as we are making changes to the original input array) into 'ans' and return 
//run a for loop for each input i.e "1", "2", "3" //we'll use swapping to create all permuatations
//for "1" => loop will be called & 1. "1" will be swapped by "1" as nums[index], nums[j] are same nums=  [1,2,3] // 2.call solve func again with index + 1,,,index = 1 (i.e 2) , for loop for 2,3 = for "2" = 2 will be swapped by 2 && and for "3" = as only j++ is done, index is 1 (i.e 2) => 2 and 3 will be swapped => nums = [1,3,2]
// again solve func(index + 1) i.e now index = 2 (i.e 3) => 3 will be swapped by 3 and base case would be breached => [1,2,3] && [1,3,2] will be pushed into ans arr
// now there is one problem which will be solved by bactracking 
// when we return from func => we have nums = [1,3,2] // and later on in the for loop when we call for j=2,3 , we will have nums = [1,3,2] , which will give us wrong answer
// so we need to revert nums back to its original state (i.e [1,2,3]) // so we'll \swap(nums[index], nums[j]);\  swap again while returning so it'll be in its original state
// similary like "1" , we'll call for "2",  "3" as we'll for next 'for loop' iterations  using recursion //just like "1", we'll get output that we'll push into 'ans' arr and use bactracking to revert to original state
 // dry run and watch the diagram in video(39) (i.e recursion tree) to understand deeply

int main () {
    class Solution {
    
    private: 
            
        void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
            
            //base case
            if(index >= nums.size()) {
                ans.push_back(nums);
                return;
            }
            
            for(int j = index; j < nums.size(); j++) {
                swap(nums[index], nums[j]);
                solve(nums, ans, index+1);
                //backtrack
                swap(nums[index], nums[j]);
            }
        }
        
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};
return 0;
}