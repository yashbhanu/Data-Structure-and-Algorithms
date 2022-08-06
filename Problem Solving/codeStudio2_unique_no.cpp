#include <iostream>
using namespace std;

//find unique i.e {2,2,4,1,6,4,6} => ans = 1 => i.e appearing only once
//use XOR operator here to eliminate duplicates i.e  if XOR is performed on same values i.e (2^2 => 0) it returns 0, else (i.e 0 ^ 8 => 8)

int findUnique (int arr[],int n) {
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = ans^arr[i];
    }
    cout<<ans;    
}

int main(){

    int arr[8] = {2,2,4,8,6,4,6};

    findUnique (arr, 7);
return 0;
}