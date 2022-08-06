#include <iostream>
using namespace std;
 
//given a integer , reverse it eg. 321 => 123
//if a no. is outside the scope of int(i.e greater than 2^31-1 && less than 2^31) then return 0
//if ans > int_max(in built in) && ans < int_min() then return 0; 
//if a number is on the verge of 2^31-1 i.e just behind/inside (2^31-1 i.e INT_max), then it will get multplied by 10(formula) and go out of the scope of int then that would cause error//
// hence we divide it int_max && int_min by 10

int main(){
    int n;
    cin>>n;

    int ans = 0;

    while(n!=0) {

        int digit = n%10;

        if( (ans  > INT_MAX/10) || (ans < INT_MIN/10) ){
            return 0;
        }
        ans = (ans*10) + digit;

        n = n/10;
    }
    cout<<ans;

return 0;
}