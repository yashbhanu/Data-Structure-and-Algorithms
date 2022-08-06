#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int i = 2;
    int sum = 0;
    while (i <= a)
    {
        sum = sum + i;
        i = i + 2;
    }
    cout << "Sum is " << sum << endl;

    return 0;
}