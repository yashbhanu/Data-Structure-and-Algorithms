#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//given a string => "the sky is blue" //we need to reverse the words // expected OP => eht yks si eulb
//set j = 0 i.e (pointing towards 1st elem) //iterate the string by 'i' //if any space ' ' OR null '\0' is encountered , then reverse the word
//reverse(s.begin() + j, s.begin() + i) => means 1st iteration j = 0, s.begin(0) + j(0) = 0 i.e first index i.e 't' ,,, s.begin() + i = 0 + 3 = 3 //i.e reverse(0,3)index => eht
//update j value as (j = i+1) i.e one position next to i i.e 's' //continue till all words are reversed

void reverseWords(string &s) {
    int j = 0;
    for(int i = 0; i <=s.length(); i++) {
        if(s[i] == ' '||s[i] == '\0') {
            reverse(s.begin() + j, s.begin() + i);
            j = i + 1;
        }
    }
    // reverse(s.begin(), s.end());
}

int main() {
    string s = "the sky is blue";

    cout<<s<<endl;

    reverseWords(s);
    cout<<s;


return 0;    
}