#include <iostream>
using namespace std;
 
int main(){

    /*
    
    *****
     ****
      ***
       **
        *
    */


    int n;
    cin>>n;

    int row= 1;

    while(row <= n) {

        //print space
        int space = row - 1;
        while(space){
            cout<<" ";
            space--;
        }

        //print stars
        int col = 1;
        while(col<= n - row + 1){
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }
return 0;
}