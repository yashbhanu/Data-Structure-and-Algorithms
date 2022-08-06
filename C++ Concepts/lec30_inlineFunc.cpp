#include <iostream>
using namespace std;

//inline functions are those functions whole func body is of one line // they improve efficiency and performance
inline int getMax(int& a, int& b) {
    return (a>b) ? a : b;       //ternary operator
}

int main() {

    int a = 1, b = 2;

    int ans = 0;

    ans = getMax(a,b);
    cout << ans << endl;

    a = a + 3;
    b = b + 1;

    ans = getMax(a,b);
    cout << ans << endl;
return 0;    
}