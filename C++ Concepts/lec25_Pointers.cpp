#include <iostream>
using namespace std;
 
int main(){

    int num = 5;

    cout<<num<<endl;

    //address of Operating - &

    cout<<"address of num is "<<&num<<endl;

    int *ptr = &num;    //stored address of a num in a pointer

    cout<<"address is "<<ptr<<endl;
    cout<<"value is :"<<*ptr<<endl;

    cout<<"size of int is "<<sizeof(num) <<endl;
    cout<<"size of pointer is "<<sizeof(ptr)<<endl;

    //another way to initialize and access
    int i = 5;
    int *q = 0;
    q = &i;
    cout<<q<<endl;
    cout<<*q<<endl;

    //incrementing via a pointer
    int num1 = 5;
    int *p = &num;
    cout<<"before "<<num<<endl;
    (*p)++;
    cout<<"after"<<num<<endl;

    //copying a pointer
    int *a = p;     //pointer pointing to pointer
    cout<< p << "-" << a <<endl;
    cout<< *p << "-" << *a <<endl;

    //important concept - incrementing value && incrementinga address
    int i = 3;
    int *t = &i;        //pointer t pointing to value at the address of i
    // (*t => value at that particular address) (t => address itself)
    *t = *t + 1;        //incrementing value stored at that address (i.e 3 => 4) 
    cout<< "before t "<<t<<endl;
    t = t + 1;          //incrementing address itself //but how does the address gets incremented ? // as a int is of 4 bits , it gets incremented by 4 bits (i.e it goes to next integer/value/character) //from one block to another block
    cout<< "after t "<<t<<endl;

return 0;
}