#include <iostream>
#include<stack>
using namespace std;

//reverse elems in stack using recursion


void insertAtBottom(stack<int>& stack, int element) {
    //base case // if stack is empty, that is we have reached the bottom hence push 'x' into stack and return
    if(stack.empty()) {
        stack.push(element);
        return;
    }
    
    //if base case not breached means we have not reached the bottom, && save the upper elem and pop it one by one till we reach bottom
    int num = stack.top();
    stack.pop();

    //RECURSIVE CALL 
    insertAtBottom(stack, element);
    
    //after bottom elem is pushed, and we return push the upper elem back into the stack (i.e backtracking)
    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    //base case // if stack is empty return
    if(stack.empty()) {
        return;
    }
    
    //save num and pop if stack isnt empty
    int num = stack.top();
    stack.pop();
    
    //RECURSIVE CALL // keep popping elements until stack is empty
    reverseStack(stack);        
    
    //as soon as stack is empty(base case breached), insert the elements at bottom one by one
    insertAtBottom(stack,num);
}
 
int main(){

return 0;
}