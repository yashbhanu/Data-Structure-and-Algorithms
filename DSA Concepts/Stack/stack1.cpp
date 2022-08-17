#include<iostream>
#include<stack>

using namespace std;

int main() {

    //creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop
    s.pop();

    cout << "Print top elem " << s.top() << endl;

    if(s.empty()) {
        cout << "stack is empty " << endl;
    }
    else {
        cout << "stack is not empty " << endl;
    }

return 0;
}