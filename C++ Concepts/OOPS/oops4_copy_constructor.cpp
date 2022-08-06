#include <iostream>
using namespace std;
 
class Hero {
    public:

    int health; char level;

     int getHealth() {
        return health;
    }

    Hero(int health, char level) {
        this->health = health;
        this->level = level;
    }

    //print
    void print() {
        cout << "health " << health << endl;
        cout << "level " << level << endl; 
    }

    //custom created copy constructor (pass by reference bcz it'll create a copy)
    Hero(Hero &temp) {
        cout << "copy contructor called " << endl;
        //we are passing 'S' into our args (i.e Hero &temp)
        this->health = temp.health;     //this->health means => current object (i.e R) ka health = temp.health (i.e temp (i.e S) ka health) // toh R m copy hogya S ka Health 
        this->level = temp.level;
    }


};

int main(){

Hero S(70,'A');
S.print();

//copy constructor => copying properties of object S into R
Hero R(S);
R.print();
    

return 0;
}