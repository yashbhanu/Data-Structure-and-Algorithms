#include <iostream>
using namespace std;
 
int arithemtic (int n) {
    int ans = 3 * n + 7;
    return ans;        
}

int main(){
    int num;
    cout<<"Enter the nth term"<<endl;
    cin>>num;

    int answer = arithemtic(num);
    cout<<answer<<endl;
return 0;
}