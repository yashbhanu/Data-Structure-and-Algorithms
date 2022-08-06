#include <iostream>
using namespace std;
 
int main(){
    int Rs500,Rs100, Rs50, Rs20, Rs1;
    int amount;
    cout<<"Enter the amount"<<endl;
    cin>>amount;

    switch(1)  {
        case 1 : Rs500 = amount/500;
        amount = amount%500;
        cout<<"Number of 500Rs required: "<<Rs500<<endl;

        case 2 : Rs100 = amount/100;
        amount = amount%100;
        cout<<"Number of 100Rs required: "<<Rs100<<endl;

        case 3 : Rs50 = amount/50;
        amount = amount%50;
        cout<<"Number of 50Rs required: "<<Rs50<<endl;

        case 4 : Rs20 = amount/20;
        amount = amount%20;
        cout<<"Number of 20Rs required: "<<Rs20<<endl;

        case 5 : Rs1 = amount/1;
        amount = amount%1;
        cout<<"Number of 1Rs required: "<<Rs1<<endl;
    }
return 0;
}