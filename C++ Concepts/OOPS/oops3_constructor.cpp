#include <iostream>
using namespace std;
 
//constructor is kind of a function only  // a func that invokes itself when object is created of that particular class
// constructor name is same as class name

class Hero {

    public:

    int health;

     int getHealth() {
        return health;
    }

    //constructor
    Hero() {
        cout << "contructor called " << endl;
    }

    //parameterized constructor
    Hero(int health) {
        cout << "this =>" << this << endl;      //'this' is a pointer 
        // " 'this -> health' is pointing to 'int health' above && health = health in the func call" 
        this -> health  = health;       //'this' current object ke address ko store karta hai 

        // cout <<this && cout << &h will print the same values i.e (the address of h) 
        //'this' will store value of 'h' object  // when we say this->health // it points to 'h object k andar ka health (ie int health)'  // and when we say only 'health' within the func woh func args ke 'health' ko point karta h 
    }
};

int main(){

    //static
    Hero h(10);     //calling the contructor and passing '10' to its args
    cout << "Adddress of h "<< &h << endl;
    h.getHealth();

    Hero *b = new Hero;



return 0;
}