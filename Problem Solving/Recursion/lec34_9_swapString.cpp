#include <iostream>
using namespace std;

void swap(string& str, int i, int n) {

    // cout << "call for " << str << endl;

    //base case
    if(i > str.length()/2) return;       //string has been swapped , now reverse

    swap(str[i], str[n - i - 1]);       //swap elems
    i++;                 // 

    //recursive call
    swap(str, i, n);
}
 
int main(){

    string name = "abcde";

    swap(name, 0 , name.length());

    cout << name << endl;
return 0;
}