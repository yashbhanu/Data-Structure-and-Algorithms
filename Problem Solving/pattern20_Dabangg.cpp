#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin>>n;

    /*
    1234554321
    1234**4321
    123****321
    12******21
    1********1
    */

   //divide into smaller parts

    int i = 1;
    while(i <= n) {

        //traingle 1
        int j = 1;
        int count = 1;
        while(j <= n - i + 1){
            cout<<count;
            count++;
            j++;
        }

        //triangle 2
        int k = 1;
        while(k <= i -1) {
            cout<<"*";
            k++;
        }

        //traingle 3
        int a = 1;
        while(a <= i -1) {
            cout<<"*";
            a++;
        }

        //triangle 4
        int b = 1;
        int count2 = n - i + 1;
        while(b <= n - i + 1) {
            cout<<count2;
            count2--;
            b++;
        }



        cout<<endl;
        i++;
    }
return 0;
}