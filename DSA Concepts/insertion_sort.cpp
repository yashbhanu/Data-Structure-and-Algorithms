#include <iostream>
using namespace std;
#include <bits/stdc++.h>


//Insertion Sort (refer book)
//given an array => [10,1,7,4,8,2,11]
//think of an example of a card ,how you sort it//take 1st 2 elems of array [10,1] //check if 10 > 1 => True ,shift them //dont swap //shiftt...
//there would be n - 1 rounds (eg 6) //for loop 'i' => iterate array from 2nd to lastElem [1,7,4,8,2,11] //store elem in 'temp' var i.e temp = 1
//for loop 'j' => iterate array backwards (eg. if is at '4') , then iterare from 7 [10,1,7]
//dry run => i = 1th index = 1 //j = i- 1 = 10 //temp = 1 //check if arr[j] (i.e 10) > temp (i.e 1) (2nd elem of array and 1st elem of arr) 10 > 1  => rue
//shift 10 rightwards i.e arr[j] i.e 10 = arr[j+1] // now arr= [10,10,7,4,8,2,11] //j-- i.e j = -1 //now j + 1 = 0th position which is 10 //place '1' which is stored in temp on j + 1 i.e 0th pos //now arr => [1,10,7,4,8,2,11]
//continue till it gets sorted



void insertionSort(vector<int> arr, int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        for (; j>=0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
        }
        arr[j + 1] = temp;
    }
}



int main() {

    int arr[7] = {10,1,7,4,8,2,11};
return 0;
}