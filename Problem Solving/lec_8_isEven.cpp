#include <iostream>
using namespace std;
 
//isEven
//1 -> even
//2 -> odd

//check every binary no. from 1-15 //every even no. ends with 0 in binary and every odd no. ends with 1 in binary
//we perform '&' operation //if 0&1 then => 0 , if 1&1 then => 1, so every odd no. will return 1 which would make if stat. true and it would return 0 for odd. no.s else its an even
/*
bool isEven(int number) {
    if(number&1) {  //odd
        return 0;
    }
    else{       //even
        return 1;
    }
}

int main(){
    int num;
    cin>>num;

    if(isEven(num)) {
        cout<<"Number is Even"<<endl;
    } else {
        cout<<"Number is Odd"<<endl;
*/


// isPrime
// 1 -> is Prime
// 0 -> is not a Prime

//if no. get divided by any no. from 2 to n-1 , then its not a prime no.

bool isPrime(int n) {

    for (int i = 2; i < n; i++)
    {
        //divide hogya matlab not a prime
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
    
}
int main() {
    int n;
    cin>>n;
    if(isPrime(n)) {
        cout<<"Number is prime"<<endl;
    } else {
        cout<<"Number is not a prime"<<endl;
    }

return 0;
}