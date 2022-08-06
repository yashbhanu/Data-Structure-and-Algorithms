#include <iostream>
using namespace std;

//find power // given => a,b (i.e 2,3) => we need to find 2^3 = 2*2*2 = 3
// multiply '2' n no. of times (i.e multiply '2', '3' times) => but this isnt optimized soln => do it by recursion for more optimized soln
//if(b == 0) return 1 => i.e (if 2^0 = 1 OR 3^0 = 1)  //if (b == 1) return a => i.e (if 2^1 = 2 OR 3^1 = 3) // hence return 'a'
// now, if we want to find 2^10 then halve it (2^5 * 2^5 = 2^10) // hence call the func again by dividing b/2
//now if b is even (i.e 2^4 then return 2^2 * 2^2)  // but if b is odd (ie 2^5 then return (2^2 * 2^2 *2) = 2^5) to get accurate figure
//dry run to understand properly

int power(int a, int b) {

    //base case
    if (b == 0) return 1;
    
    if (b == 1) return a;

    //recursive call
    int ans = power(a, b/2);

    // if b is even
    if(b%2 == 0) {
        return ans * ans;
    }

    else {
        // if b is odd
        return a * ans * ans;
    }
}
 
int main(){

    int a,b;

    cin >> a >> b;

    int ans = power(a,b);

    cout << ans << endl;
return 0;
}