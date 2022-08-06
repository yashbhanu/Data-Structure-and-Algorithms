#include <iostream>
using namespace std;

//find nth term of fibonacci
// fibonacci no.s => 0,1,1,2,3,5,8,13,21  //1st term =>0, 2nd term => 1, 3rd => 1, 4th => 2, 5th => 3, 6th => 8.....
//if input 'n' is given as '5' then find the 5th term i.e 3 ,etc


int fibonacci(int n) {
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    int a = 0;
    int b = 1;
    int nextNumber;
    for (int i = 1; i<=n-2; i++)
    {
        nextNumber = a + b;
        a = b;
        b = nextNumber;
    }
    return nextNumber;
}

int main(){
    int num;
    cout<<"Enter the no."<<endl;
    cin>>num;
    int answer = fibonacci(num);
    cout<<answer<<endl;
return 0;
}