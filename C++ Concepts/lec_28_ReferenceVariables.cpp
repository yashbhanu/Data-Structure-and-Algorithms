#include <iostream>
using namespace std;

//pass by value - where we pass the value and a copy is created for that variable (i.e new memory is allocated) // and changes happend in that new copy created // No changes in main()
void update1(int j) {
    j++;
}

//pass by reference - where we give a reference variable and it is pointing to a the memory block of variable in main() // new copy IS NOT created //Changes in main() // memory same hai naam alag hai
void update2(int& j) {
    j++;
} 

int main(){
/*
    int i = 5;

    //create a ref variable
    int& j = i;

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;
    cout << j << endl;
*/

int n = 5;
cout << "Before " << n <<endl;
update2(n);
cout << "After " << n <<endl;



return 0;
}