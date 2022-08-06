#include <iostream>
using namespace std;

//class is like a template(blue print) // object is an instance of class
//access modifiers - 1. pubic = anything can accessed from anywhere 2. private = cannot be accessed directly , but can be accessed wihtin that same class
//getter and setter => to access and set some variable's values respc  // //using getter and setter we can access private members also

class Hero {

    //properties

    private:
    char level;
    public:
    int health;

    void print() {
        cout << level << endl;
    }

    //getter
    int getHealth() {
        return health;
    }

    //setter
    void setHealth(int h) {
        health = h;
    }

    //getter
    char getlevel() { 
        return level;
    }

    //setter
    void setlevel(char l) {
        level = l;
    }
};
 
int main(){
    
    //creation of object
    Hero h1;

    cout << sizeof(h1) << endl;

    // h1.health = 70;      //set health

    //setter and getter
    h1.setHealth(70);
    h1.setlevel('A');      //using getter and setter we can access private member

    cout << h1.getHealth() <<endl;
    cout << h1.getlevel() << endl;      //using getter and setter we can access private member


return 0;
}