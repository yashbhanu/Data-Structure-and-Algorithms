#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//You are given an array [-8, 2, 3, -6, 10] and k (eg k = 2) // check First negative integer in every window of size k 
// i.e k=2 , so check 1st 2 int.s in array i.e[-8,2] => here negative int = -8 , so push -8 in answer // check next window [2,3] =>no -ve ,so push 0 // next [3,-6] => push -6 // next [-6,10] => push -6 
// ans  = [-8,0,-6,-6]
//Approach 
//first process for the first window // create a deque and push the index of negative no. // push the negative no. in array
// process for remaining windows // pop the index val from deque if negative no. exists in further window and push tat negative window in answer array , if no -ve doesnt exists, push 0

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long>ans;
    
    //process first window
    for(int i = 0; i < K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);        //check if -ve no. exists, push index of negative no. in deque
        }
    }
    
    //push ans for first window 
    if(dq.size() > 0) {
        ans.push_back(A[dq.front()]);       //if deque is not empty, then push ans(i.e -ve no.)
    }
    else {
        ans.push_back(0);       // if no -ve doesnt exists, push 0
    }
    
    //now process for further/remaining windows
    for(int i = K; i < N; i++) {
        //first pop out from window element // check if deque is empty, if not empty then check does the element(index) stored in deque's front comes in the current k size window(jo elem deque k front m hai, kya woh current k window size m aati h kya)
        if(!dq.empty() && i-dq.front() >= K) { 
            dq.pop_front();     //if yes , then pop from front
        }
        
        //then push current element
        if(A[i] < 0) {
            dq.push_back(i);        //push the new negative elem's index in deque
        }
        
        //push ans for remaining window
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
    }
    return ans;
}
 
int main(){

return 0;
}