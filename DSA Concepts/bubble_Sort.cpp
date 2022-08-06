#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//HW => stable o unstable //in place sort

//Bubble Sort (refer book)
//given an array => [1,7,6,10,9,14] //sort elements by swap (a,b) if a > b (i.e [arr[i]] > arr[i+1] swap(arr[i], arr[i+1])) 
//we need to perform n-1 rounds //(Eg. 5) //for every round swap a,b elems
//loop 1 => iterate 0-5 rounds// loop 2 => iterate array (0 - secondlastelem) (eg 1 - 9) if(arr[j] > arr[j+1] i.e if 1st elem grater than 2nd elem swap it) //j++ //iterate whole array and swap
//round 1 => swap elems till (1,7,6,10,9,14)(after round 1 lastelem will be placed at right/correct position) //round 2 => update j (1,7,6,10,9) //swap elem //continue till n - 1 rounds
//set a var bool swapped = false // it goes j loop and swaps elems then swapped = true //if sorting is over in round 2 iteself.... 
//we dont need to go to further rounds //suppose in round 2 arr is sorted //it goes to round 3 , bool swapped remains false // it goes in j loop and when doesnt swap any elems , gets out of j loop and if(swapped = false) , then break from i loop(i.e rounds)

void bubbleSort(vector<int> arr, int n) {
    for (int i = 0; i < n - 1; i++){
    bool swapped = false;
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j] , arr[j+1]);
                swapped = true;
			}
		}
        if (swapped = false)
        break;
	}
}


int main() {

    int arr[6] = {1,7,6,10,9,14};

return 0;    
}