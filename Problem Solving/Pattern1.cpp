#include <iostream>
using namespace std;

int main()
{

    /*
     ***
     ***
     ***
     */
    // take the no. of rows and columns to print
    int n;
    cin >> n;

    int i = 1;
    // for row
    while (i <= n)
    {
        // for column
        int j = 1;
        while (j <= n)
        {
            cout << "*";
            j = j + 1;
        }
        // next line
        cout << endl;
        i = i + 1;
    }
    return 0;
}