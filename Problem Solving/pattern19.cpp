#include <iostream>
using namespace std;
 
int main(){

    /*
       1
      121
     12321
    1234321
    */


    int n;
    cin>>n;

    int row = 1;
    while (row<=n) {

        //print space
        int space = n - row;
        while(space) {
            cout<<" ";
            space--;
        } 


        //print triangle 1
        int col = 1;
        while(col<=row) {
            cout<<col;
            col++;
        }

        //print triangle 2
        int start = row - 1;
        while(start){
            cout<<start;
            start--;
        }

        cout<<endl;
        row++;

    } 
return 0;
}