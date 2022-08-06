#include <iostream>
using namespace std;

//power of 2
//comapare if the given input matches the power of 2(i.e 2^0,2^1,2^2,2^3,2^4,etc....)
//if matches then true else false

int main(){
    int n;
    cin>>n;

    int ans = 1;

    for (int i = 0; i <= 30; i++)
    {
        if (ans == n) {  
            cout<<"true";
            break;
        }    
        if (ans < INT_MAX/2){
        ans = ans * 2;
        // cout<<ans;
        }
    }
    if(ans != n) {
        cout<<"false";
    }
    
    
    
return 0;
}