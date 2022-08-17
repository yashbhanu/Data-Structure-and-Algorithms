#include <iostream>
#include<stack>
using namespace std;

//insert the given element (i.e x)in bottom of stacl => myStack = [1,2,4,5] & x = 9 => then Output =  myStack = [1,2,4,5,9]
//we'll use recursion and backtracking 
//

void solve(stack<int>& myStack, int x) {
    //base case // if stack is empty, that is we have reached the bottom hence push 'x' into stack and return
    if(myStack.empty()) {
        myStack.push(x);
        return;
    }
    
    //if base case not breached means we have not reached the bottom, && save the upper elem and pop it one by one till we reach bottom
    int num = myStack.top();
    myStack.pop();

    //RECURSIVE CALL 
    solve(myStack, x);
    
    //after bottom elem is pushed, and we return push the upper elem back into the stack (i.e backtracking)
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);          //pass stack and x to solve func
    return myStack;
}



int main(){

return 0;
}