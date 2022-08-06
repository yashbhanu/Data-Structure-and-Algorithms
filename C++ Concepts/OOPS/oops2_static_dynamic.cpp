#include <iostream>
using namespace std;

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

int main() {

    //static allocation
    Hero a;
    a.setHealth(80);
    a.setlevel('B');
    cout << "level is" << a.getlevel() << endl;
    cout << "health is" << a.health << endl;

    // dynamic allocation
    Hero *b = new Hero;
    b->setHealth(70);
    b->setlevel('A');
    // derefernce (*b)
    cout << "level is" << (*b).getlevel() << endl;
    cout << "health is" << (*b).getHealth() << endl;
    cout << "level is" << b->getlevel() << endl;
    cout << "health is" << b->getHealth() << endl;


return 0;
}