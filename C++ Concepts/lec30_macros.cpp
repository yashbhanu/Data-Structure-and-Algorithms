#include <iostream>
using namespace std;

//global variable - anyone can use it from anywhere // dont use it => bad practice
int score = 15;

// the macro will replace all the 'PI' with 3.14 // macro wont consume any space/memory and cant be updated
//declaration of a macro
#define PI 3.14

int main() {

    int r = 5;
    //double pi = 3.14;     //this shall consume space and can be updated

    double area = PI * r * r;

    cout << area <<endl;
return 0;    
}