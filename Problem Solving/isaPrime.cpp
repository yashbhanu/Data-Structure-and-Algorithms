#include <iostream>
using namespace std;
 

/* Prime no.s - 2,3,5,7,9,11,13  i.e no.s which arent divisible by self and 1 (jo no. 1 ke table aur apne khudke table ko chodke kisi aur table m 'naa aaye') not divisible by (2 to n -1)  */
/*iterate the user input no.(eg. 7) starting from 2 till (n - 1) i.e (7-1 =6)) 
if its divisible by any one no. (eg. (n =6) then 6/2 ==0 , then not a prime no.) then set the the var isPrime = 0 and break the loop
if its not divisible by any no. (eg. (n=7) then (7/2 to 6) != 0, then its a prime no. and hence isPrime = 1 will remain)*/

int main(){

    int n;
    cout<<"Enter value of n"<<endl;
    cin>>n;

    bool isPrime = 1;

    for (int i = 2; i<n; i++)
    {
        
        //rem = 0 , Not a prime
        if(n%i==0) {

            isPrime = 0;
            break;
        }
    }

    if(isPrime == 0) {
        cout<<"Not a Prime Number";
    } else{
        cout<<"is a Prime Number";
    }
    
return 0;
}