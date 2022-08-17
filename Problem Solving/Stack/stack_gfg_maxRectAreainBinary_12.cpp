#include <iostream>
#include<bits/stdc++.h>
#include<limits.h>
#include <MAX>      //included to nullify error in vs code for int M[MAX][MAX]

using namespace std;


//given an array {{0 1 1 0},   find the largest area of rectangle (i.e 1s), visualize the 1s in histogram // here the largest rectangle is row[1][2] combined (i.e area = 8)
//               {1 1 1 1},
//               {1 1 1 1},
//               {1 1 0 0}}
//step 1 -> first condsider, the 1st row => {0 1 1 0} => calculate area for it , area = 2 // consider it in a form of histogram // use largestRectangleArea() func from prev.problem
//step 2 -> now consider 2nd row and add 1st and 2nd row (1,2,2,1) and calculate area // area = 4
// step 3 -> now consider 3rd row and add the already combined 1st and 2nd row with 3rd row => {2,3,3,2} => area = 8
// step 4 -> now consider 4th row and add the already combined 1st ,2nd, 3rd row with 4th row => {3,3,0,0} => area = 6 //  considering elems starting form 0 as 0 and not adding it up , bcz rect cannot start from 0
// considering the max area  



class Solution{
  public:
    
    vector<int> nextSmallerElement(int* arr, int n) {
    stack<int> s;
    s.push(-1);         //push -1 bcz if there doesnt exist any small elem, we'll return -1
    vector<int> ans(n);         //answer vector of size n
    
    for(int i = n-1; i >= 0; i--) {             //iterate for behind
        int curr = arr[i];                      //extract last elem
        while(s.top() != -1 && arr[s.top()] >= curr) {                //compare the curr elem with top elem in stack
            s.pop();                // if stack's top elem is greater than pop,keep popping till you find small elem
        }
        //after you find top elem is less than curr elem , exit while loop and...
        //the top of stack is the ans
        ans[i] = s.top();
        s.push(i);           //push curr into stack and continue backward iteration
    }
    return ans;             //return array as ans
}
    
    vector<int> prevSmallerElement(int* arr, int n) {
    stack<int> s;
    s.push(-1);         //push -1 bcz if there doesnt exist any small elem, we'll return -1
    vector<int> ans(n);         //answer vector of size n
    
    for(int i = 0; i < n ; i++) {             //iterate for behind
        int curr = arr[i];                      //extract last elem
        while(s.top() != -1 && arr[s.top()] >= curr) {                //compare the curr elem with top elem in stack
            s.pop();                // if stack's top elem is greater than pop,keep popping till you find small elem
        }
        //after you find top elem is less than curr elem , exit while loop and...
        //the top of stack is the ans
        ans[i] = s.top();
        s.push(i);           //push curr into stack and continue backward iteration
    }
    return ans;             //return array as ans
}
  
  
    int largestRectangleArea(int* heights, int n) {
        //int n = heights.size();             //size of array // no.of histograms
        
        vector <int> next(n);
        next = nextSmallerElement(heights,n);           //get an array for next smaller elem for each current elem and -1 for those who do not any smaller elem // for [2,1,5,6,2,3] => [1,-1,2,2,-1,-1]
        
        vector <int> prev(n);
        prev = prevSmallerElement(heights,n);          //get an array for prev smaller elem for each current elem and -1 for those who do not any smaller elem // for [2,1,5,6,2,3] => [-1,-1,1,1,1,1]
            
        int area = INT_MIN;             //decalare area for histogram acquiring max area // initially set to minimum of integer
        for(int i = 0; i < n; i++) {            //iterate the heights array
            
            int l = heights[i];         //get the length (alreay given)
            
            if(next[i] == -1) {             //if next of any elem in arr is -1 the set it to n(size of array/no.of histograms) => eg . [2,1,5,6,2,3] => n=6
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;          //use the formula to get width(breadth)
            int newArea = l*b;                      //calculate area // for every iteration, calculate area for each histogram
            area = max(area,newArea);               //select the largest area acquired by histogram
        }
        return area;
    }
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        //compute area of first row
        int area = largestRectangleArea(M[0], m);
        
        //for remaining rows
        for(int i = 1; i < n; i++) {
            
            for(int j = 0; j < m; j++) {
                
                //row update : by adding previous row's value to curr. row
                if(M[i][j] != 0) {              //only if not starting from 0
                    M[i][j] = M[i][j] + M[i-1][j];              //every iteration , row will be added and area will be calculated // {0 1 1 0} += (1,2,2,1) += {2,3,3,2} += {3,3,0,0}
                } 
                else {
                    M[i][j] = 0;                //if start from 0, then consider it 0
                }
            }
            //entire row is updated // calculate area for updated row
            int newArea = largestRectangleArea(M[i], m);
            area = max(area,newArea);           //select maxArea
        }
        
        return area;
    }
};


int main() {

return 0;
}
 