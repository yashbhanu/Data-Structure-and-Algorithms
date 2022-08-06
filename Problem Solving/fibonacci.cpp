#include <iostream>
using namespace std;
 
/*
fibonacci series -: 0 1 1 2 3 5 8 13 21...
first 2 no.s are '0' and '1';
addition of previous no. and current no. gives the next fibonacci no. i.e 0 + 1 = 1; 1 + 1 = 2; 1 + 2 = 3; etc
take a = 0 && b = 1     //i.e first 2 no.s
add them we get next no. i.e '1' store it in var nextNumber
now we need to add currentNumber i.e (nextNumber) and previous no. i.e (b)
hence, make a = b(i.e previous no.) && b = nextNumber (i.e currentNumber)
and add a + b in a loop to get n no.s

*/

int main(){
    int n;
    cin>>n;

    int a = 0;
    int b = 1;

    cout<<a <<" "<<b<<" "; 
    for (int i = 1; i<=n; i++)
    {
        int nextNumber = a + b;
        cout<<nextNumber<<" ";

        a = b;
        b = nextNumber;
    }
     
return 0;
}