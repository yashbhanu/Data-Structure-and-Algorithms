#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// you are given an array ["coding", "coder", "codeninjas", "codezen"] // find the longest common prefix(i.e the first common char.s in a string) //  here "cod" is the common prefix
//Approach => take the first char in the first string and check if it matches with first char of other strings | if it matches then push it into ans && continue same prcoess for other char.s & doesnt matches then break from the func.
// T.C -> O(n*m) , S.C -> O(1)

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";        // ans string
    
    //for traversing all char.s of first string
    for(int i = 0; i < arr[0].length(); i++) {
        
        char ch = arr[0][i];        // take char.s from 1st string 
        
        bool match = true;          // flag to check if matches true or not
        
        //for traversing remaining words of string 
        for(int j = 1; j < n; j++) {
            
            //not match // mark false and break
            if(arr[j].size() < i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }
        // after comparing with all char.s of string check if match is false -> yes then break
        if(match == false) {
            break;
        }
        else {
            // else char from first string matches all char from other strings | hence push char into ans
            ans.push_back(ch);
        }
    }
    return ans;
}


int main() {

return 0;
}