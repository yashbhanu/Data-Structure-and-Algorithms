#include <iostream>
using namespace std;

/*
1
23
456
*/

int main(){
    int n;
    cin>>n;

    // int row = 1;
    // int count = 1;
    // while(row<=n){

    //     int col = 1;
    //     while(col<=row){
    //         cout<<count<<" ";
    //         count++;
    //         col++;
    //     }
    //     cout<<endl;
    //     row++;
    // }

    //similar
    /*
    1
    23
    345
    4567
    56789
    */

   int row = 1;
    while(row<=n){

        int col = 1;
        while(col<=row){
            cout<<(row + col - 1)<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
return 0;
}