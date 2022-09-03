#include <iostream>
#include <queue>
using namespace std;

int main() {

    //create a queue
    queue <int> q;

    q.push(11);
    q.push(13);
    q.push(15);

    cout << "front of q is: " << q.front() << endl;
    cout << "size is :" << q.size() << endl;

    q.pop();
    q.pop();

    cout << "front of q is: " << q.front() << endl;
    cout << "size is :" << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty " << endl;
    } else {
        cout << "queue is not empty " << endl;
    }

return 0;
}