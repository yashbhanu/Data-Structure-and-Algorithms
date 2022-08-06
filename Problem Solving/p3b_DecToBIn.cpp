#include <iostream>
#include <math.h>
using namespace std;


//wrong
int main(){

    int n;
    cout<<"Enter negative decimal no."<<endl;
    cin>>n;

    int i = 0;
    int ans = 0;

    if(n<0) {
        n = -1 * n;
    }

    while (n!=0)    
    {
        int bit = n&1; //read last bit
        ans = ans + (bit* pow(10,i));
        n = n>>1;   //helps to read the other bits by shifting it to the right
        i++;
    }

    cout<<"Binary is "<<(~ans +1 ) * -1;
    


return 0;
}