#include <iostream>
using namespace std;

//fibonacci series => 0,1,1,2,3,5,8,13,21
//its an addition of previous 2 no.s
//you'll be given nth term // you must find nth term of fibonacci series // series starts froms 0th index // => 0 = 0nth term // 1 = 1nth term // 1 = 2nth term //2 = 3nth term // 3 = 4nth term....
//set the base case 1 and 0
//recursive rel => fib(n - 1) + fib(n - 2) => i.e addition of previous no. + previous to previous no.

int fib(int n) {   
        //base case
        if (n == 0) return 0;
        
        if (n == 1) return 1;
        
        //recursive relation
        int ans = fib(n - 1) + fib(n - 2);
        
        return ans;
}

int main(){

    int n;
    cin >> n;

    int ans = fib(n);

return 0;
}