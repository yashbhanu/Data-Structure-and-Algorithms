#include <iostream>
using namespace std;

void update (int **p2) {
    // p2 = p2 + 1;
    //any change - no // bcz we create a copy of p2 and update it // so no change in main()

    // *p2 = *p2 + 1;
    //any change - yes // bcz we create a copy of p2 // in p2 address of p is stored //we go to p's address and update the value stored in p (i.e i's address + 1) 

    **p2 = **p2 + 1;
    //any change - yes // bcz we create a copy of p2 // in p2 address of p is stored //we go to p's address and as there is one more star(*) we go to the address stored in p (i.e i's address)// we go to i's address and update the value on that address (i.e 5 + 1 = 6)
}
 
int main(){

    int i = 5;
    int *p = &i;
    int **p2 = &p;

    /*
    cout << i << endl;      //print 5
    cout << *p << endl;     // or print value of address stored in p (i.e 5)
    cout << **p2 <<endl;    // address of p stored in p2 // go to the address of p2 //now print value of address stored in p (i.e 5)
    

    cout << &i << endl;     //print address of i
    cout << p <<endl;       //print address stored in p (i.e address of i)
    cout <<*p2 <<endl;      //go to address stored in p2 (i.e p's address) // now print value stored in p (i.e i's address)

    cout << &p <<endl;      //print address of p
    cout << p2 <<endl;      //print value stored in p2 (i.e p's address)
    */

   cout << "before " << i <<endl;
   cout << "before " << p <<endl;
   cout << "before " << p2 <<endl;
    update(p2);
   cout << "after " << i <<endl;
   cout << "after " << p <<endl;
   cout << "after " << p2 <<endl;


return 0;
}