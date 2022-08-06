#include <iostream>
using namespace std;

//single inheritance => inherting properties of one class to another
class Animal {

    public:
    int age, weight;

    void speak() {
        cout << "bol rha hu " << endl;
    }
};

class Dog: public Animal {

};
 
int main(){

    Dog d;
    d.speak();
    cout << d.age << endl;

return 0;
}