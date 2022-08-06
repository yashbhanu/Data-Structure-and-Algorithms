#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//book allocation (Refer book for detailed explaination)
//given an array => [10,20,30,40] i.e books //allocate it to 'm' no. stud.s (eg 2)
//case 1 = 10 => student 1 && 20|30|40 => student 2
//case 2 = 10|20 => student 1 && 30|40 => student 2 .....etc
//case 1: 0 + 10 = 10 ,, 20 + 30 + 40 = 90 (max = 90)
//case 2 : 10 + 20 = 30 ,, 30 + 40 = 70 (max = 70)...etc
//Commbine All cases max numbers i.e [90,70,60] //find the minimum here i.e 60
//How ??
//use BS => sum of all array elems = 10+20+30+40 = 100 //apply BS on 0 - 100 //set start, end, mid
//check if 'mid' value is possible solution or not (Eg mid[50]) //if False then apply BS on right part(greater values) (51-100) //if True the iterate the left part(smaller values) (51-75) and store the ans
//keep on doing BS till you find right answer
//how to find if mid[50] is possible solution or not //check ifsum of array elements are smaller or greater than mid i.e 50 (eg 10 <= 50 => T, 10+20 <= 50 => T, 10+20+30 != 50=> F)
//if True and iteration over array is over => return true (possible solution)
//if False and iteration over array is not over => return fALSE (not a possible solution)


bool isPossible(vector <int> array, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for(int i = 0; i<n; i++) {
        if(pageSum + array[i] <= mid) {
            pageSum += array[i];
        }
        else {
            studentCount++;
            if(studentCount > m || array[i] > mid) {
                return false;
            }
            pageSum = array[i];
        }
    }
    return true;
}



int allocateBooks(vector <int> arr, int n, int m) {
    int s = 0;
    int sum = 0;

    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e - s)/2;

    while(s <= e) {
        if (isPossible(arr, n, m ,mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
 
int main(){

    vector <int> arr = {10,20,30,40};

    int minValue = allocateBooks(arr,4,2);
    cout<<"The minimum value for maximum value cases is "<<minValue<<endl;

return 0;
}
