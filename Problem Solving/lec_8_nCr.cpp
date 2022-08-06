#include <iostream>
using namespace std;
 
// Formula => nCr = n!/r!*(n - r)! i.e 8C1 = 8!/1!*(8-1)!
//First => function for factorial Second => function to implement formula

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int nCr (int n, int r) {
    int num = factorial(n);

    int denom = factorial(r) * factorial(n - r);

    int ans = num/denom;
    return ans;
}

int main(){
    int n,r; 
    cin>>n>>r;
    int answer = nCr(n,r);
    cout<<answer;
return 0;
}