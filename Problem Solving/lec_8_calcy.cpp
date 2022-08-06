#include <iostream>
using namespace std;
 
int main(){

    int a,b;
    cout<<"Enter the value of a"<<endl;
    cin>>a;
    cout<<"Enter the value of b"<<endl;
    cin>>b;

    char value;
    cout<<"Enter the operation you want to perform"<<endl;
    cout<<"+ - * / %"<<endl;
    cin>>value;

    switch(value) {
        case '+' : cout<< (a+b) <<endl;
                break;

        case '-' : cout<< (a-b) <<endl;
                break;
        
        case '*' : cout<< (a*b) <<endl;
                break;
        
        case '/' : cout<< (a/b) <<endl;
                break;

        case '%' : cout<< (a%b) <<endl;
                break;

        default: cout<< "Please enter a valid operation"<<endl;
                break; 
    }

return 0;
}