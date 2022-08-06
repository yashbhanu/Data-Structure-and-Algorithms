#include <iostream>
using namespace std;

//Inheritance => inheriting properties of parent class into child class

class Human {

    
    public:
    int height;

    protected:
    int weight;

    private:
    int age;

    public:

    int getweight() {
        return this->weight;
    }

    int setweight (int w) {
        this->weight = w;
    }
};

//inheritance using public mode // can acccess height  // can acccess weight (but has to set a getter to access outside)  //cannot access age
class Male1: public Human {
    public: 
    string color;

    void sleep() {
        cout << "Sleeping " << endl;
    }
};

//inheritance using protected mode // can access weight & height (but needs to set a getter to access outside) //cannot access age
class Male2: protected Human {
    public: 
    string color;

    void sleep() {
        cout << "Sleeping " << endl;
    }
};

//inheritance using private mode // cannot access anything
class Male3: private Human {
    public: 
    string color;

    void sleep() {
        cout << "Sleeping " << endl;
    }
};


int main(){

    Male1 obj1;
    obj1.color;
    obj1.height;
    // obj1.weight;
    obj1.sleep();

return 0;
}