#include <iostream>
using namespace std;

//Encapsulation => wrapping up data members and functions in capsule // capsule => class
//its used for information/data hiding
//In fully encapsulated clas => everything is marked as private

//the below is encapsulation

class Hero {

    private:
        int id;
        string name;
        int age;
    
    public:
        int getAge() {
            return this->age;
        }
};
 
int main(){

return 0;
}