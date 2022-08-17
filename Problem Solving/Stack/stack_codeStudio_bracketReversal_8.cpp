#include <iostream>
#include <stack>
using namespace std;

//Question => you'll be given a string of brackets // the barckets either might be balanced or unbalanced // balanced => '{{}}' , unbalanced = '{{}{'
//You need to find out the minimum cost to make a string valid // {{}} => already balance hence cost = 0 // '{{{}' => reverse the 2nd bracket to make it balanced , cost = 1
//eg . => '{{{}' 
//step 1 => first remove the valid expression from string i.e '{{{}' => '{{'
//step 2 => calculate the cost to make '{{' this a valid string => but how ? => count closed brackets and open bracket (for '{{' CB = 0 & OB = 2) // and put it into a formula (a+1)/2 + (b+1)/2    // ans = 1 => right ans
// (a+1)/2 + (b+1)/2 for '{{{{' => ans = 2 => right ans

int findMinimumCost(string str) {
    
    //odd condition => not possible at all
    if(str.length()%2 == 1) {
        return -1;
    } 
    
    //even condition
    stack<char> s;
    //iterate the string
    for(int i = 0; i<str.length(); i++) {
        char ch = str[i];           //extract each char from string
        
        // STEP 1 => remove valid expression
        //if its an opening bracket => simply push into stack
        if(ch == '{') {
            s.push(ch);
        }
        else {
            //ch is a closed bracket
            if(!s.empty() && s.top() == '{') {          //if not empty and top is a OB('{') , that means a corresponding opening bracket exits for the closing bracket (i.e a valid expression)
                s.pop();            //remove(pop) dat valid expression
            }
            else {
                //stack is empty and 1st bracket is closing bracket => push it
                s.push(ch);
            }
        }
    }
    
    //popped out valid expression part from original string // now stack contains only invalid expression
    //STEP2 => count min. cost for balancing invalid expression
    int a = 0, b = 0;           
    while(!s.empty()) {         //iterate stack till its empty
        if(s.top() == '{') {            //if OB, count b++
             b++;   
        }
        else {
           a++;   //if CB, count a++
        }
        //get count for OB and CB
        s.pop();            //and keep popping the char.s from stack, till its empty and count CB nd OB
    }
    int ans = (a+1)/2 + (b+1)/2;            //put no. of CB and OB in formula to get right ans about min. cost
    return ans;
}


int main() {

return 0;
}