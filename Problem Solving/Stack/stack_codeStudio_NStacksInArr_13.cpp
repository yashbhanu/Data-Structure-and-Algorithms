#include <iostream>
#include<bits/stdc++.h>


// fit 'K' stacks in and N sized array // an array of size n = 6 => [1,2,3,4,5,6] // k = 3 // so we have to create 3 stacks and fit into the array of size n


class NStack
{
public:
    // Initialize your data structure.
    int *arr;            //our array which shall implement the stack
    int *top;            // an array which will have top() elems of each stack
    int *next;           // an array which shall point to next space (i.e elem 1 ka next free space hai elem 2 , elem 2 ka next free space h elem 3)
    
    int n,s;
    int freespot;    //will have index of the next free spot in the array/stack
    NStack(int N, int S)
    {
        //constructor to initialzize our stack data structure
        n = N;
        s = S;
        arr = new int[s];            //array of size s 
        top = new int[n];        //top array of size n(i.e no. of stack) 
        next = new int[s];        //next array of size s(i.e same size as size of array)
        
        //top initialize
        for(int i = 0; i < n; i++) {
            top[i] = -1;         //as stacks will be empty initially, all top values would be -1        // top = [-1,-1,-1] // each elem represents top of each stack  
        }
        
        //initialize next
        for(int i = 0; i < s; i++) {
            next[i] = i+1;          //i+1 bcz 0th indexing 
        }
        
        next[s-1] = -1;      //if s = 6 then  => [1,2,3,4,5,-1] // update last elem of stack to -1 // pointing to next free space // initially , for 0th elm in arr ,next free space is at index 1 in arr,  for 1th elm in arr ,next free space is at index 2 in arr
        
        // initialize freespot          //initally for empty stack/arr , its 0
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //push into array/stack //eg given => (10,1) => 10 ko push kardo stack 1 main // eg given => (20,2) => 20 ko push kardo stack 2 main
        //check for overflow
        if(freespot == -1) {
            return false;
        }
        // given => (10,1)
        //find index ki kaha push krna h arr/stack m
        int index = freespot;
        
        //insert elems into array
        arr[index] = x;
        
        //update freespot   //freesport = next[0] i.e freesport = 1 // i.e 0th elem m humne kar diya h push // now next freesport on index 1 in arr
        freespot = next[index];
        
        //update next           // next[0] = top[1-1] // next[0] = -1 // i.e [-1,2,3,4,5,-1] => elem at 0th position in arr/stack (i.e last pos.) ka next elem hai -1(bcz last elem)
         next[index] = top[m-1];
        
        //update top
        top[m-1] = index;           // top[0] = 0 => [0,-1,-1] // top of 0th stack(i.e 1st stack) is at index 0 of array
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //pop elems // write the push code in reverse order(bottom to top)
        //check if any elem exist(underflow)
        if(top[m-1] == -1) 
            return -1;
        
        int index = top[m-1];        //get index ki konsa pop krna h
        
        top[m-1] = next[index];        //update top // top[0] = next[0] // top[0]= -1 // [-1,-1,-1] , popped last elem , now empty stack
        
        next[index] = freespot;         //update next // next[0] = 1; [1,2,3,4,5-1] // reverted again
        
        freespot = index;        //update freespot // freespot = 0; // reverted again
        
        return arr[index];      //returned the popped elem
    }
};

int main() {

return 0;
}