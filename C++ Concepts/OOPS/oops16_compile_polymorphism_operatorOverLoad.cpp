#include <iostream>
using namespace std;

//operator overloading =>jab me kisi operator ki functionality badal du
//eg '+' => plus operator ki functionality badal dunga (i.e overload)

class B {

    public:
    int a;
    int b;

    int add() {
        return a+b;
    }

    //whenever I call '+' it'll run the below function // take value 1 and value 2 and subtract it // so when I use addition (+) operator , it'll subtract => this is overloading
    void operator+ (B &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "OP " << value1 - value2 << endl;
    }
};

int main(){

    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;        //called '+' and it'll subtract 7-4 = 3

return 0;
}