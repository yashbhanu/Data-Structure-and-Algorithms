#include <iostream>
using namespace std;

//sort 0s 1s 2s
// you are given an array => [1,1,0,2,2,0,1,2] => sort it into 0's and 1s 2s => [0 0 1 1 1 2 2 2]
//initialize 3 variables left=0[start], mid=0[start] && right=n-1[end]
//run the loop till mid exceeds right[end]; //pass the mid value to switch case and check inside the array
//mid[i] is iterating the array as we are passing it to switch() case
//case 1 : if there is 1 in the array then let it be just move mid++;
//case 2 : if mid[i] iterates and finds 2 in the array then swap the arr[mid] i.e '2' to arr[right] i.e end of the array //move mid++ and right[end]--;
//case 0 : if mid[i] iterates and finds 0 in the array then swap the arr[left][start] i.e '0' to arr[mid] //move left++ and mid++;
//IN SHORT we are just putting 2's in the end and 0's at the beginning and let be the 1's 


void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortOneTwo (int arr[], int n) {
    int left = 0;
    int mid = 0;
    int right = n - 1;

    while(mid <= right) {
        switch(arr[mid]) {
            
            case 0:
            swap(arr[left++], arr[mid++]);
            break; 

            case 1:
            mid++;
            break;

            case 2:
            swap(arr[mid], arr[right--]);
            break;
        }
    }

}
int main(){
    int arr[8] = {1,1,0,2,2,0,1,2};

    sortOneTwo(arr, 8);
    printArray(arr, 8);
return 0;
}