#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//just reverse a queue
//first push all the queue elements in stack
//then pull all the elements from stack in queue(as stack LIFO, it reverses and puts back into queue)


queue<int> rev(queue<int> q)
{
    stack <int> s;
    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

int main(){

return 0;
}