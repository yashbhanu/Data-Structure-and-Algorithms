#include <iostream>
#include <stack>
using namespace std;
 
//sort a stack => stack = [2,1,5,7] => [7,5,2,1]

void sortedInsert(stack<int> &stack, int num) {
    //base case
    //if empty or top elem is smaller than num(num is to be inserted) , then push and return
    if(stack.empty() || (!stack.empty() && stack.top() < num)) {
        stack.push(num);
        return;
    }
    
    //if base case not breached, save and pop the top elem
    int n = stack.top();
    stack.pop();
    
    //RECURSIVE CALL // keep calling till stack is empty or top < num // and insert elem in sorted way
    sortedInsert(stack,num);
    
    //backtracking => insert the elems(i.e n) back which were greater than top
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
	//base case
    if(stack.empty()) {
        return;
    }
    
    //extract no. from stack , save it pop it
    int num = stack.top();
    stack.pop();
    
    //RECURSIVE CALL // keep on calling recursive func till stack is empty
    sortStack(stack);
    
    //as soon as stack is empty(base case breached) , it returns and calls the below func. // now we have to insert the elem(ie. num in a sorted order)
    sortedInsert(stack,num);
}

int main(){

return 0;
}