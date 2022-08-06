#include <iostream>
using namespace std;

//doesnt work here // run in codeStudio 
//we need to find duplicates in an array
//first iterate all the elements of an array i.e(4,2,5,3,5) and XOR it '^' ie 4^2^5^3^5
//then iterate through 1 to size - 1 i.e (1-4) and XOR it with array elements (4^2^1^3^1)^(1^2^3^4) 
//in xor repeated values will be returned as zero i.e we will be left with '1' only

int findDuplicate(int arr[], int size) {
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
        cout<<ans<<endl;
    }

    for (int i = 1; i < size; i++)
    {
        ans = ans^i;
        cout<<ans<<endl;
    }
    cout<<ans;
}

int main(){
    int arr[5] = {4,2,1,3,1};

    findDuplicate(arr, 5);
return 0;
}