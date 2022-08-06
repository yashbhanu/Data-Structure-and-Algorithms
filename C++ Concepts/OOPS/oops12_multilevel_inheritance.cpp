#include <iostream>
using namespace std;

class Animal {

    public:
    int age, weight;

    void speak() {
        cout << "bol rha hu " << endl;
    }
};

class Dog: public Animal {

};

//multilevel
class Labrador: public Animal {

};
 
int main(){

    Dog d;
    d.speak();
    cout << d.age << endl;

    Labrador lab;
    lab.speak();
    cout << lab.age << endl;



return 0;
}