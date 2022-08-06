#include <iostream>
using namespace std;
 
int main(){

    /*
    
    1234
     234
      34
       4
       
    */


    int n;
    cin>>n;

    int row= 1;

    while(row <= n) {
    int count = row;

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
            count++;
            col++;
        }
        cout<<endl;
        row++;
    }
return 0;
}