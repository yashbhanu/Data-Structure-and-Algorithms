#include <iostream>
using namespace std;
#include <bits/stdc++.h>


//Phone key pad problem :- have a look at the phone keypad // no. 2- 9 is mapped with a particular string like 2=>"abc", 3=>"def"....
//prob stat => you are given a input "23", when you press "23" on keypad, what are the possibilities of letters to be typed // OP => ["ad","ae","af","bd","be","bf","cd","ce","cf"] = "23" gives you 9 such possibilities
// you need to output those possible strings i.e ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//arr 'ans' is where you'll store your main ans (i.e main array) //if string is empty then return empty arr[] // set a empty 'output' string where you'll push your possible answers
//create a array mapping which maps string to particular index number // 1 & 0 are empty // 2-9 have the mapping // call the solve func sending everything as args
//here we'll include a approach of include // in include we'll include elem
// index shall iterate the input array (eg (2,3)) // base case = when whole array will be iterated then return // but when whole will be iterated ? => when all output blocks are created // so push all output arr blocks into 'ans' and return
// get the number in "23" by digit[index] // but it'll give us a char "2" , to convert it back to int , subtract it by '0' // asscii value substracted and int 2 will return (google ascii values)
//get string mapped to that particular number "string value = mapping[number];" // for 2 => "abc"
// run a for loop for each string elem "a", "b", "c" // push back that particular elem for which loop is running // output = "a" // then call solve again for index + 1 
// now index = 1 (i.e 3) // get 3's mapping "def" // run for loop for "def"  // push_back "d", "e", "f" in output // as "a" is already inputted // "ad", "ae", "af" 
// for loop for "b", "c" will run and we'll get and then index + 1 //loop for "def" // we'll get "bd", "be","bf" //similarly "cd", "ce", "cf"
// we got the answers but there is a problem // we'll use backtracking to solve it 
//when run loop for "a", we push_back "a", then "ad", "ae","af", then solve(index+1) // base case breached // "ad", "ae","af" push_backed into ans and we return 
// when we return and inside for loop go to the next elem (i.e b) //in output string , we already have "a" // so when calling for "b", answers would be "abd", "abe".....which is WRONGG
// hence we remove(i.e pop_back) "a" from output string while returning from recursive functions => this is backtracking**




int main () {

    class Solution {
    private:
    
void solve(string digit, string mapping[], string output, int index, vector <string>& ans)     {
        //base case
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';   //get char value in int
        string value = mapping[number];
        
        for(int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, mapping, output, index+1, ans);     //recursion
            output.pop_back();      //backtracking
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector <string> ans;
        
        if(digits.length() == 0) {
            return ans;
        }
        
        string output = "";
        int index = 0;
        
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(digits, mapping, output, index, ans);
        return ans;
        
    }
};

return 0;
}