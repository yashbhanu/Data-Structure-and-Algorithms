#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//remove Substring
//given a string = "daabcbaabcbc" and part = "abc" //we need to remove 'abc' from string on every loop iteration //excepted OP => "dab"
//while string is not equal to zero and and if the part exists within the string and is less than str.length()? If True run the loop
//find func finds the part provided within the string // erase func erases the part given within the string
//erase the abc part on every loop iteration 


string removeSubstring (string str, string part) {

    while (str.length() != 0 && str.find(part) < str.length()) {
        str.erase(str.find(part), part.length());
    }
    return str;
}

int main(){

    string s = "daabcbaabcbc";
    string part = "abc";

    cout<<removeSubstring(s,part);

return 0;
}