#include <iostream>
using namespace std;
 
/* we are given a number n = 234 we have to find sum of the digits & product of digits and subtract it
eg n=234 prod= 2*3*4 = 24 & sum = 2+3+4=9 ,,,subtract = 24-9=15 =>ans */

int main(){

    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    int prod = 1;
    int sum = 0;

    while (n!=0)
    {
        int digit = n%10;
        prod  = prod * digit;
        sum = sum + digit;

        n = n/10;
    }

    int answer = prod - sum;
    cout<<answer;


return 0;
}