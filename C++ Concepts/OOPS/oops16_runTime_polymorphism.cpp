#include <iostream>
using namespace std;

//run time polymorphism => its decided during run time that which function/method will be executed // on run time its decided that what would happen 
//run time polymorphism = method overriding**
//when we create a class (eg Animal) // and within Animal create a class named speak() {with logic as "speaking"}
// and then when we inherit Dog from Animal // we override the function/method speak()  // we create a different implemention of the function/method speak() in Dog class => i.e func overriding  // one name , diffrent roles


class Animal {

    public:
    void speak() {
        cout << "Speaking " << endl;
    }
};

class Dog : public Animal {

    public:
    //method/function overriding // create another implementation of method speak()
    void speak() {
        cout << "Barking " << endl;
    }
};

int main(){

    Dog obj;
    obj.speak();        // now when we create obj of class Dog // and call speak() => it'll invoke the function/method speak() of Dog class // i.e Output = "Barking"

return 0;
}