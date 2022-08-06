#include <iostream>
using namespace std;
 
//complement of base 10
//7 is '111' in binary if we reverse it i.e (~n=7) then answer will be '000' i.e 0
//10 is '1010' in binary if we reverse it i.e (~n=10) then answer will be '0101'i.e 5

int main(){
    int n;
    cin>>n;

    int m = n;
    int mask = 0;

    //edge case
    if(n == 0) {
        return 1;
    }

    while (m!=0)
    {   
        mask = (mask << 1) | 1;
        m = m >> 1;
    }

    int ans = (~n) & mask;
    cout<<ans;
    
return 0;
}