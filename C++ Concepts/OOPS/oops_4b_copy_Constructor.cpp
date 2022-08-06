#include <iostream>
using namespace std;
 
class Hero {
    public:

    int health; char level;

        Hero(int health, char level) {
        this->health = health;
        this->level = level;
        }

    void print() {
        cout << "health " << this->health << ",";
        cout << "level " << this->level << ",";
    }

};

int main(){

    Hero hero1(70,'B');

    Hero hero2(60, 'C');

    hero1.print();
    hero2.print();

    hero1 = hero2;      //copy assignment operator // copying hero2's values into hero1

    hero1.print();
    hero2.print();

return 0;
}