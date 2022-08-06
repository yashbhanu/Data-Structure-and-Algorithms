#include <iostream>
using namespace std;

//given  => a string = "A man, a plan, a canal: Panama" // if we remove the extra/faltu chars i.e (, ,:) then => amanaplanacanalpanama =>this is a palindrome
//we have to remove faltu chars from string and check if its palindrome or not

//check if char is valid or not //if it lies between a-z|A-Z|0-9 , then its valid //if a faltu char(, ,:) is comes then func returns false //and goes to the next char
bool valid(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1;
        }
        return 0;
}

//converrt to lowercase //if lies between a-z OR 0-9 return char as it it //if not convert to lowercase
char toLowerCase(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
        return ch;
    } else {
        char temp = ch - 'A' + 'a';     //check previous program for explaination    
        return temp;
    }
}

//check palindrome or not //pass string to it eg(amanaplanacanalpanama) //set start = firstelem , end = lastelem //if elems are not equal to each other then false //else s++, e-- ,i.e keep iterating from both ends if elem == elems  //return True if all elems === elems
bool checkPalindrome(string a) {
    int s= 0;
    int e = a.length()-1;

    while(s<=e) {
        if((a[s]) != (a[e])){
            return 0;
        }
        else {
            s++;e--;
        }
    }
    return 1;
}

bool isPalindrome(string s) {
        //faltu char hatado
        string temp ="";            //create a empty string
        
        //iterate the string given //iterate through each n every character // check if its valid or not //if valid push into string temp  //end result will be => AmanaplanacanalPanama
        for(int j = 0; j<s.length(); j++) {
            if(valid(s[j])) {
                temp.push_back(s[j]);
            }
        }
        
        //convert the string obtained (AmanaplanacanalPanama) into lowercase //iterate each character of string and convert to lowercase if Capital //end result => amanaplanacanalpanama
        for(int j = 0; j <temp.length();j++) {
            temp[j] = toLowerCase(temp[j]);
        }
        
        //check if the string obtained(amanaplanacanalpanama) is palindrome or not
        return checkPalindrome(temp);
        
}

int main(){

    string s = "A man, a plan, a canal: Panama";


    cout<<isPalindrome(s);
return 0;
}