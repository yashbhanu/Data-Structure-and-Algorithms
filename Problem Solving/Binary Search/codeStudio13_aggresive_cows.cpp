#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//aggresive cows (refer book)
//given - array [4,2,1,3,6] => stalls //k = 2 i.e no. of cows (which are to be allocated on stalls)
//find min. difference bw all elements of array and return max. value of all min. values
//sort array => [1,2,3,4,6] => use BS => s = 0, e = largest value = 6, set mid(eg 3)
//check if mid[3] possible or not //how ?? //iterate the array //check if the difference bw first elem and all other elems is greater or equal to mid //keep updating first elem (i.e lastPos)
//if difference is >= mid , increase cowCount, 
//then check if cowCount = k , if true => return true //i.e mid[3] is possible soln //ifPossible = true, then store ans=mid, then update s, apply BS on larger values //if false then vice versa
//keep on doing till while() doesnt end //as while ends , returned the stored ans i.e (5)



bool isPossible(vector <int> &stalls, int k,int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i = 0; i<stalls.size(); i++) {
        if(stalls[i] - lastPos >= mid) {
            cowCount++;
            if(cowCount == k) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}


int aggressiveCows(vector <int> &stalls, int k){
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < stalls.size(); i++) {
        maxi = max(maxi, stalls[i]);
    }
    int n = stalls.size();
    int e = stalls[n - 1];
    // cout<<"size is "<<e<<endl;
    // cout<<maxi;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e) {
        if(isPossible(stalls, k, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector <int> stalls = {4,2,1,3,6};
    int k = 2;

    int maxValue = aggressiveCows(stalls, k);

    cout<<"The value is "<<maxValue<<endl;
return 0;
}
