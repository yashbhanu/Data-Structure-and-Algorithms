#include <iostream>
using namespace std;

bool checkPalindrome(string str, int i) {

    //base case
    if(i >= str.length()) return true;

    if(str[i] != str[str.length() -i - 1]) {
        return false;
    } else {
        //recursive call
        return checkPalindrome(str, i+1);
    }
}
 
int main(){

    string name = "BookkooB";

    bool isPalindrome = checkPalindrome(name, 0);

    if(isPalindrome) {
        cout << "Its a palindrome " << endl;
    }
    else {
        cout << "Its not a palindrome " << endl;
    }
return 0;
}