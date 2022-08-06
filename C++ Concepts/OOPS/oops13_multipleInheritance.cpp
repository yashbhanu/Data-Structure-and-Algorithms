#include <iostream>
using namespace std;

class A {

    public:
    int age, weight;

    void speak() {
        cout << "bol rha hu " << endl;
    }
};

class B {
    public:
    string color;

    void bark() {
        cout << "barking " << endl; 
    }
};

//multiple
class C: public A, public B{

};
 
int main(){

    C d;
    d.speak();
    d.bark();
    cout << d.age << endl;
    cout << d.weight << endl;



return 0;
}