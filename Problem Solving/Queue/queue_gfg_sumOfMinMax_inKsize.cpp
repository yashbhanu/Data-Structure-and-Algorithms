#include <iostream>
#include <deque>
using namespace std;


// Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
// Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
// K = 4
// Output : 18
// Explanation : Subarrays of size 4 are : 
//      {2, 5, -1, 7},   min + max = -1 + 7 = 6
//      {5, -1, 7, -3},  min + max = -3 + 7 = 4      
//      {-1, 7, -3, -1}, min + max = -3 + 7 = 4
//      {7, -3, -1, -2}, min + max = -3 + 7 = 4 

//Approach => consider 1st k size window , push the max and min elem in respective deque and find out the sum (i.e ans = 6)
// remove old elem and add new elem to consider remaining k size windows, and find out the sum



int solve(int *arr, int n, int k) {

    deque<int> maxi(k);         //deque to track max elem in k size window(i.e 4)
    deque<int> mini(k);         //deque to track min elem in k size window(i.e 4)

    //Addition/Sum of first k size window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) 
        {
            maxi.pop_back();        //if any elem inside the maxi deque is smaller than current elem(i.e i), then pop back the old elem
        }

        while (!mini.empty() && arr[mini.back()] >= arr[i]) 
        {
            mini.pop_back();        //if any elem inside the mini deque is greater than current elem(i.e i), then pop back the old elem
        }

        maxi.push_back(i);      //push the index of max element found
        mini.push_back(i);      //pus the index of min element found
    }

    //now we have max elem of 1st k size window in maxi deque's front (maxi.front())
    //now we have mini elem of 1st k size window in mini deque's front (mini.front())
    
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];       //calculate sum for 1st k size window

    //process remaining windows
    //for processing next windows , we need to do addition of new elem and removal of old elem // arr = {2, 5, -1, 7, -3, -1, -2} => 1st k size windows = [2, 5, -1, 7] => next k size windows = [5, -1, 7, -3] (here we have removal of 2 and addition of -3) // continue the process for all the remaining windows
    for (int i = k; i < n; i++)
    {
        
        //removal
        while (!maxi.empty() && i - maxi.front() >= k)  
        {
            maxi.pop_front();       
        }

        while (!mini.empty() && i - mini.front() >= k)  
        {
            mini.pop_front();
        }

        //addition
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) 
        {
            maxi.pop_back();        
        }

        while (!mini.empty() && arr[mini.back()] >= arr[i]) 
        {
            mini.pop_back();       
        }

        maxi.push_back(i);
        mini.push_back(i);

        //calculate sum and add it for the remaining window // 
        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;

}


int main(){

    int arr[7] = {2, 5, -1, 7, -3, -1, -2};         //array

    int k = 4;      //window of size k(i.e 4)

    cout << solve(arr,7,k) << endl;

return 0;
}
