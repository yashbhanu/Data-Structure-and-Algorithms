#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//removeDuplicates
//given a string = "abbaca" //For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
//create a vector // iterate the string // if vector is empty then push s[i] elems into vector st  (i.e vector = [a])
//st.back() =  to get last elem from vector (i.e b) // check if last elem from vector (i.e a == s[i] i.e b) => False // then push s[i] i.e 'b' elem into vector st
//now vector = [a,b] //check agian if last elem(i.e b == s[i] i.e b) => True then st.pop_back() (i.e remove last elem i.e b) //continue to get end answer
//at last convert the vector into string (i.e ans) and return it


string removeDuplicates(string s) {
        vector<int> st;
        
        for (int i = 0; i < s.length(); i++) {
            if(st.empty())
                st.push_back(s[i]);
            
            else if (st.back() == s[i])
                st.pop_back();
            
            else
                st.push_back(s[i]);                
        }
        string ans(st.begin(), st.end());
        return ans;
}


int main(){

    string s = "abbaca";

    cout<<removeDuplicates(s);

return 0;
}