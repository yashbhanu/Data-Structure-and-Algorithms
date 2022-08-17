#include<iostream>
using namespace std;

class Stack {

    //properties
    public:
        int *arr;
        int top;
        int size;
    
    //behaviour  // as soon as I'll create a stack using an object, the following constructor shall be initialized
    Stack(int size) {
        this -> size = size;        //current object's size  = size(size passed in constructor's paramter)
        arr = new int[size];        // dynamically create a new array of provided size
        top = -1;                   //initialize top elem as-1 
    }

    //push
    void push(int element) {
        //check if stack is empty
        if(size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack OverFlow" << endl;
        }
    }

    //pop
    void pop() {
        //check if element exists 
        if(top >= 0) {
            top--;
        } else {
            cout << "Stack UnderFlow" << endl;
        }
    }

    //peek => return top element
    int peek() {
        if(top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    //check if empty or not
    bool isEmpty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }
};


int main() {

    Stack st(5);

    st.push(12);
    st.push(35);
    st.push(21);

    cout << "Top elem " << st.peek() << endl;

    st.pop();

    cout << "Top elem " << st.peek() << endl;

    st.pop();

    if(st.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

return 0;
}