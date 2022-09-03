#include <iostream>
#include <queue>
#include <stack>
using namespace std;


// Function to reverse first k elements of a queue. arr = [1,2,3,4,5], k = 3, // ans = [3,2,1,4,5]


queue<int> modifyQueue(queue<int> q, int k) {
    //step 1 : pop k elems from queue and push it into stack
    stack<int> s;
    for(int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    //step 2 : fetch from stack and push it into queue(as when we remove elems from stack, it are removed in reversed order)
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    //now arr = [4,5,3,2,1] //now we need to push [4,5] behind
    //step 3 :  fetch n-k elems(i.e eh. 4,5) from queue and push it at back/behind side of queue
    int t = q.size() - k;
    
    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}


int main(){

return 0;
}