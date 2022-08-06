#include <iostream>
using namespace std;
 
// gcd (gretest common divisor)
// if there 2 no.s (36,60) then gcd  = 12 i.e 36 and 60 both are divisible by 12 and 12 is the higesht divisor of 36 and 60 both
//run loop till a == b //if a > b then a = a - b (formulae) and vice versa`
//formula shall make a == b and that value shall be gcd


int gcd (int a, int b) {
    if (a==0)
    return b;

    if(b==0)
    return a;

    while (a != b){
        if(a > b) {
            a = a-b;
        } else {
            b = b -a;
        }
    }
    return a;
}

int main(){

    int a,b;
    cout<<"Enter a and b"<<endl;
    cin>>a>>b;

    int ans = gcd(a,b);
    
    cout<<ans<<endl;

return 0;
}