#include <iostream>
#include<bits/stdc++.h>

using namespace std;


//Question => Design a stack that supports getMin() in O(1) time and O(1) extra space //i.e create a stack which shall return Min value in stack //and the min value should get updated after pushing and popping a value from stack
//And this has to be done using O(1) T.C & S.C => as O(1) space should be used , hence we'll do it in variables without any extra space
// created a stack and var mini to store minimum values // eg. now when we push 1st elem(eg. 5), push it normally and as there is only 1 elem(so 5 will be mini)
//pushed again into stack (i.e 3) => now 3 is less than 5 , so we need to update the mini , we use formula (2*data - mini) to generate a value that shall be pushed into stack so we could generate/update mini back(i.e once again) when we pop 
// val = 1 , push 1 in stack and update mini = 3 // now stack = [1 5] mini = 3 // now push 6 into stack , as 6 > 3 , no need to update (mini), simply push 6 // now stack = [6 1 5] mini = 3
// now we pop elem , extract top = 6 and pop it , as 6 > 3, mini will remian same // now stack = [1 5] mini = 3 // now pop , extract and pop it (i.e 1) as mini elem is popped we need to update mini value // hence use formula (2*mini - curr) // val = 5
// update (mini = val = 5) // mini updated // return popped elem // now stack = [5] mini = 5 // 





#include <stack>
class SpecialStack {
    // Define the data members.
    stack <int> s;        //our main stack
    int mini;            // variable in which we'll store the min. value
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element  
        if(s.empty()) {
            s.push(data);        //normal push
            mini = data;         // update mini
        }
        else {
            if(data < mini) {
                int val = 2*data - mini;    //formula to get val that'll be pushed into stack
                s.push(val);            //push val into stack // generated val so we could generate/update mini back(i.e once again) when we pop 
                mini = data;            //update mini
            }
            else {
                s.push(data);            //if data > mini, no need to update mini(it shall remain same) , hence normal push
            }
        }
    }

    int pop() {
        if(s.empty())        //chech underflow
            return -1;
        
        int curr = s.top();
        s.pop();          // get top elem and pop it
        
        // when we pop , there are 2 condition => 1. we popped minimum value, hence update mini value for remianing stack 2.we havent popped minimum(mini) value, it shall remain the same
        
        if(curr > mini) {        //cond 2
            return curr;
        }
        else {        //cond 1
            int prevMin = mini;          // extracted mini value as we are now going to update mini.
            int val = 2*mini - curr;    // formula to update/generate mini value
            mini = val;            //update mini
            return prevMin;        //return popped elem(i.e prev minimum value)
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {        
            return mini;            //we have pushed 'val' in the stack & if that 'val' is on top(), then we have to return mini , as 'val' is replacment for mini , that is pushed into stack
        } else {
            return curr;           //else simply return curr value extracted from top
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        return mini;
    }  
};

int main() {

return 0;
}