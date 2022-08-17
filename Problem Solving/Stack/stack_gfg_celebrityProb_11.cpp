#include <iostream>
#include <stack>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


//Celebrity Problem // To find out who's the celebrity
//given a 2D array {{0 1 0}, of 3*3 rows nd cols, we need to find out which one is celebrity , (0,1,2) => index of the matrix => celebrity is either 0 or 1 or 2
//                 {0 0 0}, 
//                 {0 1 0}}
//there are 2 condition to find out celebrity (i.e celebrity does not know anyone (i.e all 0's) && (all others know celebrity(i.e 1)))


class Solution 
{
    private:
    
    bool knows(vector<vector<int> >& M,int a, int b, int n) {
        if(M[a][b] == 1) {
            return true;
        } 
        else {
            return false;    
        }
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
         stack<int> s;
         
         //step 1 : push no. of 'n' elements in stack (i.e push (0,1,2))
         for(int i = 0; i < n; i++) {
             s.push(i);
         }
         //step 2 : get 2 elems and compare them // compare top 2 elems on the top of stack and check whether they know each other
         while(s.size() > 1) {
             int a = s.top();
             s.pop();           //extract top elem (i.e 2) and pop
             
             int b = s.top();
             s.pop();           //extract top elem (i.e 1) and pop
             
             if(knows(M,a,b,n)) {
                 s.push(b);             //compare 2 and 1 whether they know each other (i,e M[2][1]) // if a knows b then push b back in stack bcz acc. to condition, celebrity doesnt know anyone(hence a is not celeb)
             }
             else {
                 s.push(a);         //vice versa // if b knows a , push a
             }
        }
         
         
         //Step 3 : now single element is remaining in stack which is a potential answer
         int ans = s.top();
         
         //verify the ans on 2 condition
         //-> ans should know no one (i.e every elem should be 0)
         //-> all other should know ans (i.e every elem should ne 1 except one (i.e itself))
         
         //count zeroes for potential ans(i.e it should not know anyone => i.e all zeroes)
         int zeroCount = 0;
         for(int i = 0; i < n; i++) {
             
             if(M[ans][i] == 0) {
                 zeroCount++;
             }
         }
        
        // all should be zeroes // if zeroCount is not equal to n(i.e 3) return false(-1)
         if(zeroCount != n) {
             return -1;
         }
         
         //count ones for potential ans (i.e all other elems should know ans(i.e potential ans/celebrity) => i.e all ones except itself(n-1))
         int oneCount = 0;
         for(int i = 0; i < n; i++) {
             
             if(M[i][ans] == 1) {
                 oneCount++;
             }
             
         }
            
         if(oneCount != n-1) {
             return -1;
         }         
         return ans;
     
    }
};

int main() {

return 0;
}