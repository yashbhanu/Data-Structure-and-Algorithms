#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Given an array [2,1,4,3] => find the next smallest element for each elem // for '2', outoff [1,4,3] '1' is smallest elem 
// for '1', outoff [4,3], there isnt any small elem, hence return -1 // for '4', out [3] next smallest elem is 3 // for '3' return -1
//Approach => create a stack and push -1 bcz if there doesnt exist any small elem, we'll return -1
//iterate array from behind , for '3' look into stack there is -1, -1 < 3, hence for '3' ans = 1 ,and then push 3 // for '4', look into stack, there is [3,-1] , compare 4 with 3, (4 < 3), hence for 4 ans=3 and push 4
// for '1', look into stack [4,3,-1] , 4 > 1 => hence pop 4, 3 > 1 => hence pop 3, -1 < 1 hence for 1, ans = -1 and then push 1// for '2', look into stack [1,-1], 1 < 2 => hence for 2, ans = 1
//Output array for [2,1,4,3] is => [1,-1,3,-1]
 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);         //push -1 bcz if there doesnt exist any small elem, we'll return -1
    vector<int> ans(n);         //answer vector of size n
    
    for(int i = n-1; i >= 0; i--) {             //iterate for behind
        int curr = arr[i];                      //extract last elem
        while(s.top() >= curr) {                //compare the curr elem with top elem in stack
            s.pop();                            // if stack's top elem is greater than pop,keep popping till you find small elem
        }
        //after you find top elem is less than curr elem , exit while loop and...
        //the top of stack is the ans
        ans[i] = s.top();
        s.push(curr);           //push curr into stack and continue backward iteration
    }
    return ans;             //return array as ans
}


int main() {

return 0;
}