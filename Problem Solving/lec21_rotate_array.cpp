#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//rotate array
//given => an array = [8,5,1,6,5,2] and k = no. of places elem need to be shifted   eg. k = 2 // OP => [5,2,8,5,1,6] i.e the elem should move 2 spaces forward
//approach => use mod 
//iterate the array //create a temp array to store values //we need to shift 2 places further ,thats why (i+k) (i.e 0 + 2, 1 + 2) //but that would cause an issue for last 2 elems
//hence we mod it with arr's size which gives ur correct indexes of arr (formula) (dry run it)  //we store it in temp vector, bcz it will overrite if we copy in original array
//lastly, copy temp back in original array



void rotate(vector <int>& arr, int k) {

    vector<int> temp(arr.size());   //vector temp with type int and size = arr.size()

    for(i = 0; i < arr.size(); i++) {
        temp[(i + k)%arr.size()] = arr[i];
    }

    //copy temp into num vector
    arr = temp;
}


int main(){
    
    vector<int> arr = {8,5,1,6,5,2};

return 0;
}













