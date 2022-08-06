#include <iostream>
using namespace std;
 
int main(){


/*
AAA
BBB
CCC
*/
    int n;
    cin>>n;

    // int row = 1;
    // while(row <= n){

    //     int col = 1;
    //     while(col <= n){
    //         char ch = 'A' + row - 1;
    //         cout<<ch;
    //         col++;
    //     }
    //     cout<<endl;
    //     row++;
    // }


    //similar 
    /*
    A B C
    A B C
    A B C
    */

    // int row = 1;
    // while(row <= n){

    //     int col = 1;
    //     while(col <= n){
    //         char ch = 'A' + col - 1;
    //         cout<<ch<<" ";
    //         col++;
    //     }
    //     cout<<endl;
    //     row++;
    // }

    //similar
    /*
    A B C
    D E F
    G H I
    */


    int row = 1;
    char start = 'A';
    while(row <= n){

        int col = 1;
        while(col <= n){
            cout<<start<<" ";
            start++;
            col++;
        }
        cout<<endl;
        row++;
    }

return 0;
}