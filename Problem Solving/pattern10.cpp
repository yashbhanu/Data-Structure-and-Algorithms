#include <iostream>
using namespace std;

/*
A
BB
CCC
DDDD
*/

int main()
{
    int n;
    cin >> n;

    // int row = 1;
    // while(row<=n) {

    //     int col = 1;
    //     while(col<=row){
    //         char ch = ('A' + row - 1);
    //         cout<<ch;
    //         col++;
    //     }
    //     cout<<endl;
    //     row++;
    // }

    // similar
    /*
    A
    BC
    DEF
    GHIJ
    */

    // int row = 1;

    // char start = 'A';
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << start;
    //         start++;
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }


    /*
    similar
    A
    BC
    CDE
    DEFG
    */

   int row = 1;
    while(row<=n) {

        int col = 1;
        while(col<=row){
            char ch = ('A' + row + col - 2);
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
    }


    return 0;
}