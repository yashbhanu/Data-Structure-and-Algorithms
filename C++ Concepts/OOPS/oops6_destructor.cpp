#include <iostream>
using namespace std;

//destructor = de allocate memory
//for statically created objects => destructor is called automatically
//for statically created objects => destructor is called manually

class Hero {
    public:
    Hero() {
        cout << "Constructor called ";
    }

    // destructor
    ~Hero() {
        cout << "Destructor called";
    }
};
 
int main(){

    //static
    Hero h1;

    //dynamic
    Hero *b = new Hero();
    // manual destructor call
    delete b;
    
return 0;
}