#include <iostream>
using namespace std;

class A {

    public:
    int age, weight;

    void speak() {
        cout << "bol rha hu " << endl;
    }
};

class B : public A{
    public:
    string color;

    void bark() {
        cout << "barking " << endl; 
    }
};

//heirrachical
class C: public A {

};

//hybrid
class D: public B, public C {

};
 
int main(){

    C d;
    d.speak();
    cout << d.age << endl;
    cout << d.weight << endl;



return 0;
}