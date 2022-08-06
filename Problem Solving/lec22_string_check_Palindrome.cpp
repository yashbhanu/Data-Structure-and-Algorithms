#include <iostream>
using namespace std;

//convert uppercase to lowercase
//if(ch >= 'a' && ch <= 'z') means if ch between a-z then return 'ch' //i.e if already lowercase, send char as it is
//char temp = ch - 'A' + 'a'// eg. ch = 'B' means subtract 'A' by ch i.e 'B' - 'A' you'll get a difference of ascii value (ascci of 'A' = 12, ascci of 'B' = 13) //difference = 1 i.e 'a'//add 'a's ascii value //you'll get 'b' 
char toLowerCase(char ch) {
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    } else {
        char temp = ch - 'A' + 'a';     //detailed explaination in video lec 22 timestamp - 30:00mins
        return temp;
    }
}



//palindrome => noon = reverse is also noon //when reversed a string , it still remains the same //then its a palindrome
//s = startelem , e = endelem // run a loop //compare the first and last elem //if same then s++,e-- //return True (1) if every char matches with its corresponding char //return False (0) if any char doesnt match with its corresponding char  

bool checkPalindrome(char a[], int n) {
    int s= 0;
    int e = n-1;

    while(s<=e) {
        if(toLowerCase(a[s]) != toLowerCase(a[e])){
            return 0;
        }
        else {
            s++;e--;
        }
    }
    return 1;
}

int getLength(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main(){

    char name[20];
    cout<<"Enter your name "<<endl;

    cin>> name;

    cout<<"Your name is "<<name<<endl;

    int n = getLength(name);

    cout<<"Palindrome or not: "<<checkPalindrome(name, n)<<endl;

return 0;
}