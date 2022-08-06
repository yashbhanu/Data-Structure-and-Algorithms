#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//perform on codestudio
//triplet sum
//find which sum of triplet in an array is equal to s //here arr = [1,2,3,4,5] and s = 12; // ans will be [3,4,5]
//iterate the whole array 0-arr.size()//apply 2nd loop for i+1 value i.e values from 2nd position to arr.size() //apply 3rd loop for j+1 value i.e values from 3rd position to arr.size() && compare does i + j + k = s;
//we need values in sorted order hence we first push min value and here we push max value //and later sort the array


int main(){

    vector <vector<int> > ans;      //vector/array to store answer
    int arr[6] = {1,2,3,4,5};
    int size = 5;
    int s = 12;

	// sort(arr.begin(), arr.end());
	int left, right;
	
	for (int i = 0; i<size; i++) {
		left = i + 1;
		right = size - 1;
		
		while(left < right) {
			if(arr[left] + arr[right] + arr[i] == s) {
				ans.push_back({arr[i], arr[left], arr[right]});
				int x = arr[left];
				int y = arr[right];
				
				while (left < right && arr[left] == x) {
					left++;
				}
				while (left < right && arr[right] == y) {
					right--;
				}
			}
			else if(arr[left] + arr[right] + arr[i] < s) {
				left++;
			}
			else {
				right--;
			}
		}
		while (i + 1 < size && arr[i] == arr[i + 1]) {
			i++;
		}
	}
	// return ans;
    // cout<<ans;
    

return 0;
}