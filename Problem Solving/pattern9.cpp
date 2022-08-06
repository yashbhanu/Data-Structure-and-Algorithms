#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin>>n;

    /*
    ABC
    BCD
    CDE
    */

    int row= 1;
    while(row<=n){

        int col = 1;
        while(col<=n){
            //formula
            char ch = 'A' + row + col - 2;
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
    }
return 0;
}