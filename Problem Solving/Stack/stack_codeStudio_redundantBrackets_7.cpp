#include <iostream>
#include <stack>
using namespace std;

// check if the given string has reduntant brackets // (a+b) => no redundant bracket // ((a+b)) => has redundant brackets
// we'll iterate the string and push the opening brackets and operators(+,-,*,/) in the stack // and after we encounter closing bracket ')',
// there exists a corresponding closing bracket, we'll search for a operator(+,-,*,/) between those brackets, if there exists an operator between two brackets (eg. '(a+b)'), then its not redundant
// but if we do not found an operator between 2 brackets (eg '((a+b))' => in this case the 2nd set of brackets), then its redundant

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    //iterate the whole list
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];         //extract character from string
        
        //if its an opening bracket or operator then push into a stack  // stack('(a+b)') will look like [(,+]
        if( ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {    //for closing bracket ')' or lowercase letter(ignore lowecase letter)   
            if(ch == ')') {
                bool isReduntant = true;    //declare a variable for is reduntant or not  
                while(st.top() != '(') {            //after u found a closing bracket, iterate the stack till you encounter a opening bracket (corresponding opening bracket)
                    char top = st.top();
                    //check if there exists an operator between 2 brackets // if exists than reduntant = false
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                      isReduntant = false;  
                    }
                    st.pop();       //pop the operator
                }
                if(isReduntant == true) {
                    return true;        //if there doesnt exists a operator between 2 brackets , and we encounter an opening bracket we'll exit while loop and && reduntant = true shall be returned
                }
                st.pop();           //pop the opening bracket
            }
        }
    }
    //if we iterate the whole list , that means NO redundant bracket exists(hota toh upar hi true return hojataa), hence return false(not redundant)
    return false;
}



int main() {

return 0;
}