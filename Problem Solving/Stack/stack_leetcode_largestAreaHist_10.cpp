#include <iostream>
#include <stack>
#include <vector>
using namespace std;


//watch lec 56  

//find largest area in histogram
//given an array [2,1,5,6,2,3] // these are the heights of a hist. //  we need to find largest area of a hist //
// we'll look at right and left of a hist, to know how much area it can acquire // for that we calculate nextSmallerElem and prevSmallerEleme
// now area = l*b // now height(i.e length is given) // we need to calculate breadth(i.e width) // using a formula => n - p - 1 => next - prev - 1 
//after we get width(breadth) => calculate area = l*b // calculate area for each histogram // and select the max area(i.e largest area) and return it


class Solution {
    
private:
    
    vector<int> nextSmallerElement(vector<int> arr, int n) {
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
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
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
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();             //size of array // no.of histograms
        
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
};

int main() {


}