#include <iostream>
using namespace std;
#include<stack>

//remove mid element from stack // 1 2 3 4 5 => remove mid (i.e 3) // we'll use recursion and backtracking
// mid = size/2 //we'll have a count variable && if count variable === size then mid elem found, pop it and return
// if base case not matched make a recursive call with count + 1 and save the top elem // as soon as base case is breached & mid is removed, add the elems back and return


void solve(stack<int>&inputStack,int count, int size) {
    //base case // if(count == size/2) it means we have found the mid element hence pop() it(remove it) and return // 1 2 3 4 5 => mid = 2 //base cond not matched 
    if(count == size/2) {
        inputStack.pop();
        return;
    }
    
    //if base case cond. isnt true then save the top element in a variable 'num' and pop it (i.e top = 5, save '5' and then pop it and now we have stack 1 2 3 4) 
    int num = inputStack.top();
    inputStack.pop();
    
    //RECURSIVE CALL // call func again for (1 2 3 4) with count = 1 // again base case wont match and '4'shall be saved and poped out => recursive call for stack (1 2 3) and count = 2 // base case matched and 3(i.e mid elem) will be removed and will  return
    solve(inputStack,count+1,size);
    
    //BACKTRACKING // while we return from recursive call we'll add the elems back again (i.e 4 5) // now stack = 1 2 4 5
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	int count = 0;          //declare count
    solve(inputStack,count,N);          //pass stack, count, and size in func. args
}
 
int main(){

return 0;
}