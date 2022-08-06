#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    int b = a + 1;

    // the below statement would be true and cout will be 3 bcz a's value has changed
    if ((a = 3) == b)
    {
        cout << "a" << a;
    }
    else
    {
        cout << "a+1" << a + 1;
    }
    return 0;
}