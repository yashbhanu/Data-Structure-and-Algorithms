#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//perform on codestudio
//pair sum
//find which sum of pair in an array is equal to s //here arr = [1,2,3,4,5,6] and s = 5; // ans will be [[1,4],[2,3]]
//iterate the whole array 0-arr.size()//apply 2nd loop for i+1 value i.e values from 2nd position to arr.size() && compare does i + j = s;
//we need values in sorted order hence we first push min value and here we push max value //and later sort the array


int main(){

    vector <vector<int> > ans;      //vector/array to store answer
    int arr[6] = {1,2,3,4,5,6};
    int size = 6;
    int s = 5;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(arr[i] + arr[j] == s){
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
        
    }
    sort(ans.begin(), ans.end());
    // cout<<ans;
    

return 0;
}