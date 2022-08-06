#include <iostream>
using namespace std;
 
/*
123
123
123
*/

int main(){
    int n;
    cin>>n;

    // int i = 1;

    // while (i<=n ) {
        
    //     int j =1;
    //     while (j<=n) 
    //     {
    //         cout<<j;
    //         j=j+1;    
    //     }
    //     cout<<endl;
    //     i=i+1;        
    // }

    // in reverse
    int i = 1;

    while (i<=n ) {
        
        int j =1;
        while (j<=n) 
        {
            cout<<n-j+1;
            j=j+1;    
        }
        cout<<endl;
        i=i+1;        
    }
return 0;
}