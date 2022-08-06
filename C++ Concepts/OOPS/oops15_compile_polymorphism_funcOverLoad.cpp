#include <iostream>
using namespace std;
 
//Compile time polymorphism => Function overloading
//compile time poly => when its decided before compiling that what would be executed
// func overload => repeated names of func

class A {
    public:

    //same function name with different args => hence acceptable
    void sayHello() {
        cout << "hello yash " << endl;
    }

    void sayHello(char name) {
        cout << "hello Harry " << endl;
    }

    void sayHello(string name) {
        cout << "hello bhanu " << endl;
    }
};


int main(){

    A obj;
    //compiler knows which function to run before compile time according to the arguments
    obj.sayHello();
    obj.sayHello('A');
    obj.sayHello("bro");



return 0;
}