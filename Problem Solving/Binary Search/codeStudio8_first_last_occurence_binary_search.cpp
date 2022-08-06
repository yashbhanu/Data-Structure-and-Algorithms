#include <iostream>
using namespace std;

//Given - an array [1,2,3,3,3,3,3,4,5]
//we need to find the 1st occurence of 3 i.e index 2 and last occurence i.e 6
//use binary search //declare start and end , find mid // if mid == key then store the answer and update the end (e= mid - 1) to find the 1st occcurence and vice versa for find last occurence (updating start)
//if key is grater search right part ////if key is smaller search left part


int firstOcc (int arr[], int n, int key) {
    int s = 0, e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }

        else if(key > arr[mid]) { //go to right
            s = mid + 1;
        }

        else if (key < arr[mid]) { // go to left
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
} 

int lastOcc (int arr[], int n, int key) {
    int s = 0, e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while (s <= e) {
        if (arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }

        else if(key > arr[mid]) { //go to right
            s = mid + 1;
        }

        else if (key < arr[mid]) { // go to left
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
} 


int main(){
    int arr[9] = {1,2,3,3,3,3,3,4,5};
    
    int first = firstOcc(arr, 8,3);
    int last = lastOcc(arr, 8, 3);
    int total = (last - first) + 1;

    cout<<" First occurence of 3 is at index "<<first<<endl;
    cout<<" Last occurence of 3 is at index "<<last<<endl;
    cout<<" Total Number of occurences are "<<total;

return 0;
}