#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//check if array is rotated or not // sorted => [1,2,3,4,5] , rotated => [3,4,5,1,2] , random = [3,5,7,1,4]
//in sorted => if you shall observe closely arr[i - 1]i.e previous elem is always smaller than the next (i + 1) elem // only the last elem i.e(5) is greater than nextOne i.e 1 (only one pair)
//in roated =>  if you shall observe closely arr[i - 1]i.e previous elem is always smaller than the next (i + 1) elem //only the one elem i.e(5) is greater than nextOne i.e 1  (only one pair)
// in random => there is no such pair or pattern in random
//Sorted = > set  count = 0 //iterate the array // if(nums[i - 1] > nums[i]) i.e (if previous elem is greater than next elem count++) (it wont be true in any case) //only in 1 case it would be true i.e (if(nums[n - 1] > nums[0])) i.e (5 > 1) so return 'True' if count is 1 or less than 1 i.e(0) 
//Rotated = > set  count = 0 //iterate the array // if(nums[i - 1] > nums[i]) i.e (if previous elem is greater than next elem count++) (it wont be true in any case) //only in 1 case it would be true i.e (if(nums[n - 1] > nums[0])) i.e (5 > 1) so return 'True' if count is 1 or less than 1 i.e(0) 
//in random count would exceed '1' , so that would return False 


bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for(int i = 1; i < n; i++)  {
            if(nums[i - 1] > nums[i])       
                count++;
        }
        
        if(nums[n - 1] > nums[0])
            count++;
        
        return count<=1;
}

int main(){

    vector<int> arr1 = {1,2,3,4,5};     //sorted

    vector<int> arr2 = {3,4,5,1,2};     //rotated


return 0;
}





