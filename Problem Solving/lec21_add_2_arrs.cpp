#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//add 2 arrays => arr1 = [1,2,3,4] , arr2 = [6] OP => [1,2,3,4] + [6] = [1,2,4,0]
//start iterating backwards //i = lastelem of arr1, j = lastelem of arr2 // val1 = lastelem of arr1 i.e 4, val2 = lastelem of arr2 i.e 6 // add both => sum = 10
// but we cannot directly use 10 //we have to use '0' and carry forward '1' to next elem so we could get 1240 //get carry = sum/10 (i.e 10/10) = '1' //get sum needed to be added/pushed i.e sum = sum%10 (i.e 10%10 = 0) i.e push '0' (lastelem of desired OP arr => 1240) //i--;j--
//now 'j' is been iterated but 'i' is remaining //here we use first case => if(i>=0) ,get sum = add arr[i] + carry (i.e 3 + 1 = 4) //get sum = sum%10 = '4' //get carry = sum/10 = '0' //we got our desired OP i.e (4) //push in arr //i--
//same as above if 'j' arr is lengthier => second case
//all elems are iterated but carry in the end remaining to be added //then, third case => set (sum = carry) get carry and sum //push into arr
//as we are adding from and pushing into answer array from behind we get reversed OP => i.e 0,4,2,1 // hence, reverse the array => 1,2,4,0


vector<int> reverse(vector<int>&v) {
	int s = 0; int e = v.size() - 1;
	while(s<e) {
		swap(v[s++], v[e--]);
	}
	return v;
} 


vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	
	int i = n - 1;
	int j = m - 1;
	vector <int> ans;
	int carry = 0;
	
	while(i>=0 && j>=0) {
		
		int val1 = a[i];
		int val2 = b[j];
		int sum = val1 + val2 + carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		i--;j--;
	}
	
	// first case
	while(i >= 0) {
		int sum = a[i] + carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		i--;
	}
	
	// second case
	while(j >= 0) {
		int sum = b[j] + carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
		j--;
	}
	
	//third case
	while(carry != 0) {
		int sum = carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
	}
	
	return reverse(ans);
	
}

int main(){
    vector<int> arr1 = {1,2,3,4};
    vector<int> arr2 = {6};
return 0;
}