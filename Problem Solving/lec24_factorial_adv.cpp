#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//factorial advanced
//factorial of 212 with modulo 10^9+7 (bcz factorial of 212 will surpass int32)

int factorial (int fact) {

    int mod = pow(10,9) + 7;
    int factorial = 1;

    while (fact > 0) {
        factorial = ((factorial) * (fact))%mod;
        fact--;
    }
    return factorial;
}


int main(){

    int fact;
    cout<<"Enter factorial ";
    cin>>fact;
    cout<<factorial(fact);

return 0;
}