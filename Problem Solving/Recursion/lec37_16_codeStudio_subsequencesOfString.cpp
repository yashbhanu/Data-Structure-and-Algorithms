#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//subsequences of string - solve on codestudio
// given an array - [a,b,c] => we need to find all possible subsequences = “a” , “b” , “c” , “ab” , “bc” , “ac”, “abc” => we need to output in a array
//here we'll include a approach of include and exclude // in exclude we'll exclude elem and in include we'll include elem
//output = array where one elem as an array block will be stored // and in 'ans' array all output elems(i.e array blocks) will be inserted
//soln
//call the solve func with with input arr = 'str' , 'output' arr, 'ans' arr and index
// index shall iterate the input array (a,b,c) // base case = when whole array will be iterated then return // but when whole will be iterated ? => when all output blocks are created // so push all output arr blocks into 'ans' and return
//on 1st pass base case won't be breached // index = 0 (i.e a) for exclude => call 'solve' func by index + 1 (i.e now index = 1 (i.e b)) = nothing included and everything excluded // for include => get elem (i.e str[index] = 'a') // push back in output // 'a' included
// now using recurion call again for index = 2 (include and exclude) // we have executed one step (i.e excluded && included (a)) // recursion will handle next // just index++ to iterate whole array
//dry run OR see the diagram in video (recursion tree) to understand deeply  

void solve(string str,vector<string>& ans,string output, int index) {
    
    //base case
    if(index >= str.length()) {
        if(output.length() > 0) {
            ans.push_back(output);
        }
        return;
    }
    
    //exclude
    solve(str, ans, output, index+1);
    
    //include
    char elem = str[index];
    output.push_back(elem);
    solve(str, ans, output, index+1);
}

int main(){


vector<string> subsequences(string str);
	vector <string> ans;
    string output = "";
    int index = 0;
    // solve(str, ans, output, index);
    // return ans;


return 0;
}