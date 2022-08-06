#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//run on code studio
//vector is a dynamic array
//find all duplicates in an array i.e (1,2,1) =>[1] && (2,4,6,2,8,4) => [2,4]
//use STL // sort the array from start to end => [1,1,2] && [2,2,4,4,6,8]
//iterate the sorted array if 1st and next elements match i.e 2 == 2 && 4 == 4, then push that value into ans array

int main(){
    vector<int> nums = {1,1,2};
    vector<int> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size()-1; i++)
    {
        if(nums[i] == nums[i+1]) {
            ans.push_back(nums[i]);
        }
    }
    // cout<<ans;
    
return 0;
}