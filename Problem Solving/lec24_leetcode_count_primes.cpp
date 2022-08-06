#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//count primes (by sieve of eratosthenes)
//we need to count the no. primes from 0 - n i.e if n = 10 , count no. of primes from  0-n i.e (2,3,5,7) i.e 4 // so OP => 4
// we use sieve of eratosthenes algo/approach to solve problem //i.e first mark all no. from 0 - n as primes //then unmark which comes in table of prime no.s
//dry run => create a vector of n + 1 (i.e 11) and mark every thing as True
//then mark 0 && 1 as false manually // iterate from 2 - 10 by 'i' // if prime is True then count++, i.e 1st iteration => 2 = true,count = 1, now mark everything in 2's table as false
//2*i = 2*2 = 4 = '0' i.e false ,, j = j + i (i.e 4 = 4+2 = 6 = '0' ) (6 = 6 + 2 = 8 = '0') (mark everything as false in 2's table till 10)
//now i++ i.e 3 = true ,, count++ = 2 ,, 2*3 = 6 = '0' (6 = 6 + 3 = 9 = '0') //mark everything as false in 3's table
//continue till 10 // keep marking false // and you'll get count = 4 (for n = 10)

//time complexity = O(n*log(log n)) => why watch video (lec 24) and search taylor series on google


int countPrimes(int n) {
        
        int count = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] == false;
        
        for(int i = 2; i < n; i++) {
            
            if(prime[i]) {
                count++;
                
                for(int j = 2*i; j < n; j = j + i) {
                    prime[j] = 0;
                }
            }
        }
        return count;
}


int main(){

    int n = 10;
    countPrimes(n);

return 0;
}