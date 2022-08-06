#include <iostream>
using namespace std;

//Inheritance => inheriting properties of parent class into child class

class Human {

    public:
    int height;
    int weight;

    int getweight() {
        return this->weight;
    }

    int setweight (int w) {
        this->weight = w;
    }
};

//inheritance using public mode
class Male: public Human {
    public: 
    string color;

    void sleep() {
        cout << "Sleeping " << endl;
    }
};


int main(){

    Male obj1;
    obj1.color;
    obj1.height;
    obj1.weight;
    obj1.sleep();

return 0;
}