#include <iostream>
using namespace std;
 
int main(){

    // int a = 5, b = 6;
    // // Bitwise operator
    // cout<< " a&b " <<(a&b)<<endl;
    // cout<< " a|b " <<(a|b)<<endl;;
    // cout<< " ~a " <<(~a)<<endl;
    // cout<< " a^b " <<(a^b)<<endl;

    // // left shift
    // cout<< (17>>1) <<endl;
    // cout<< (17>>2) <<endl;
    // cout<< (19<<1) <<endl;
    // cout<< (21<<2) <<endl;


    //practice
    // int a, b= 1;
    // a = 10;
    // if (++a) {
    //     cout<< "b"<<b;
    // } else{
    //     cout<< ++b;
    // }

    // int a = 1; int b = 2;

    // if(a-- > 0 && ++b > 2) {
    //     cout<< "Stage1- Inside if";
    // } else {
    //     cout<< "Stage2- inside else";
    // }
    // cout<< a <<" "<< b <<endl; 

    int a = 1;
    int b = a++;
    int c = ++a;
    cout<< b;
    cout<< c;
return 0;
}