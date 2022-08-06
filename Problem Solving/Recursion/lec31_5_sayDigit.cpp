#include <iostream>
using namespace std;

//say digits => 251 = two five one
//create an array with strings for corresponding index no.s //0th index = zero //1th index = one....
//get the last digit (eg for 251 => 1) by mod // get remaining digit(i.e for 251 => 25) by dividing
//call function again by passing n = 25 (i.e sayDigit(n=25, arr)....continue till no. gets divided till 0
// go into the func stack and print 


void sayDigit(int n,string arr[]) {
    //base case
    if(n == 0) return;

    //processing
    int digit = n % 10;
    n = n /10;

    //recursive call
    sayDigit(n, arr);

    cout << arr[digit] << " ";
}
 
int main(){

    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    
    int n;
    cin >> n;

    sayDigit(n, arr);

return 0;
}