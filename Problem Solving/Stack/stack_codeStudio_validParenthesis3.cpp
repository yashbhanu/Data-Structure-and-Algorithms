#include <iostream>
#include <stack>
using namespace std;

//VERY IMP QUESTION
// you are given a string consisting of "{" , "}" , "(", ")", "[","]" // you need to check if given strng is valid paranthesis // "{()}" => correct , "{[}]" => wrong



bool isValidParenthesis(string expression)
{
    stack<char> s;
    for(int i = 0; i < expression.length(); i++) {
        
        char ch = expression[i];        //extract the string character
        
        //if opening bracket, then push into stack
        //if closing bracket, then check & pop from stack

        //check if opening
        if(ch == '{' || ch == '[' || ch == '(') {
            s.push(ch);         //if opening then push into stack
        }
        //for closing bracket
        else {  
            if(!s.empty()) {
                //after pushing of all chars into stack , stack will look => "{["
                char top = s.top();             //extract the top elem i.e "["
                //now the extracted char from string is an closing bracket // check whether an corresponding opening bracket exists for the extracted closing bracket // if yes, then pop(), if no return false
                if( (ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') || 
                    (ch == '}' && top == '{') ) {
                    s.pop();
                }
                else {
                    return false;
                }
            }           
            else {          //if empty, return false
                return false;
            }
        }   
    }
    //after all the processing , if for every opening bracket there is an corresponsing closing bracket then elem in stack'll be popped out and stack will be empty // if empty return true, else false 
    if(s.empty())
        return true;
    else
        return false;
}

int main(){

return 0;
}