#include <iostream>
using namespace std;
#include <string.h>

class Hero {
    public:

    int health; char level;

    char *name;

    // name = new char[100];

    //constructor
    Hero(){
        cout << "Default constructor called " << endl;
        name = new char[100];    //dynamically allocated a char array 
    }

    Hero(int health, char level) {
        this->health = health;
        this->level = level;
        this->name = name;
    }

     //custom created copy constructor (pass by reference bcz it'll create a copy)
    Hero(Hero& temp) {
        cout << "copy contructor called " << endl;
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        //we are passing 'S' into our args (i.e Hero &temp)
        this->health = temp.health;     //this->health means => current object (i.e R) ka health = temp.health (i.e temp (i.e S) ka health) // toh R m copy hogya S ka Health 
        this->level = temp.level;
    }

    void print() {
        cout << "health " << this->health << ",";
        cout << "level " << this->level << ",";
        cout << "name " << this->name << endl; 
    }

    int getHealth() {
        return health;
    }

    char getlevel() {
        return level;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }
};

int main () {

    Hero hero1(30,'A');
    Hero h;
    char name[7] = "Babbar";
    hero1.setName(name);
    hero1.print();

    //default copy constructor
    Hero hero2(hero1);
    hero2.print();


    //change first letter'
    hero1.name[0] = 'G';
    hero1.print();      //prints gabbar

    hero2.print();     //also print gabbar bcz of shallow copy  //default copy constructor creates a shallow copy    

return 0;
}