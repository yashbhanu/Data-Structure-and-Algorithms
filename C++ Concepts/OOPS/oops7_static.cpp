#include <iostream>
using namespace std;
 

class Hero {
    public:
    //static variable => it belongs only to the class // can be accessed directly without creating any object
    static int time;


    //static functions => can be called from anywhere // no need to create an object to call // can only access static variables (eg. time)
    static int getTime() {
        return time;
    }

};
    //initialize static data member (i.e static var) //using scope resolution operator (Hero class ka variable time = 5) 
    int Hero::time = 5;

int main(){

    cout << Hero::time << endl;     //accessing static time varaible

    cout << Hero::getTime() << endl;    // calling static function

return 0;
}