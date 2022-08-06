#include <iostream>
using namespace std;

//replace string
//given = a string => "hey bro how are you" //replace all spaces ' ' with @40 //expected output => hey@40bro@40how@40are@40you
//iterate the string , and wherever you find ' ', replace it with @40 //func replace() => inbuilt function which takes 3 args 1=> the index at which replacement should be done (i.e i) ,2 => how much to replaceb (i.e '1' only one char i.e space ' '), 3 => the str which should be replaced (i.e @40)


string replaceString(string &str) {

    string temp = "@40";

    for (int i = 0; i < str.length(); i++) {

        if(str[i] == ' ') {
            str.replace(i, 1 , temp);
        }
    }
    return str;
}

int main() {

    string s = "hey bro how are you";

    cout<<replaceString(s)<<endl;

return 0;    
}