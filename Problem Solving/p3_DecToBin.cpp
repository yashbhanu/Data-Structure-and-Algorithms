#include <iostream>
#include <math.h>
using namespace std;
 
//binary to decimal
/*take decimal no. from user eg.5, run the loop till it doesnt reaches 0, compiler reads the no. 5 in binary i.e (101) take the every bit from 101 and display it
take the last bit '1' from '101' by 'n&1' '1&1' will be 1 and stored in var bit. apply the formula and store answer in var ans. then right shift 'n', it will become '10' from '101'
take last bit i.e 0, apply formula ,store it in var ans and repeat the processs till n!=0  */



int main(){
    int n;
    cin>>n;

    int ans = 0;
    int i = 0;

    while(n!=0) {

        int bit = n&1;

        //formula
        ans = (bit * pow(10,i)) + ans;

        n = n>>1;
        i++;
    }

    cout<<"The answer is "<<ans<<endl;
return 0;
}