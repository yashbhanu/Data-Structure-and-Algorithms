#include <iostream>
using namespace std;
 
int main(){

    /*
    
    1111
     222
      33
       4
       
    */


    int n;
    cin>>n;

    int row= 1;

    int count = 1;
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
            cout<<count;
            col++;
        }
        count++;
        cout<<endl;
        row++;
    }
return 0;
}