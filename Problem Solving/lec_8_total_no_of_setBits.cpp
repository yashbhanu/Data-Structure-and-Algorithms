#include <iostream>
using namespace std;

//total no. set bits in a and b
//eg take 2 inputs (eg. 2,3) 2 in binary => 10, 3 in binary => 11  //total 1's are 3
//count total no. set bits/1's //so ans for above will be 3

int totalSetBits (int a, int b) {
    int count = 0;
    while(a != 0) {
        if (a&1)
        {
            count++;
        }
        a = a>>1;
    }
    while(b != 0) {
        if (b&1)
        {
            count++;
        }
        b = b>>1;
    }
    return count;

}

int main(){
    int a,b;
    cout<<"Enter value of a and b"<<endl;
    cin>>a>>b;
    int ans = totalSetBits(a,b);
    cout<<"Answer is "<<ans<<endl;
return 0;
}