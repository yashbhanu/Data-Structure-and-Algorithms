#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Question -> There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 
//Ref -> https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// Problem -> Given an array [4, 3, 2, 6] with different lengths -> Connect all these length of ropes into single ropes

// Approach -> 1. Pick 2 smallest values from array (how to find 2 smallest values? -> using min heap) 2. push all values in array into min heap 3. pick 2 smallest values , add it and & append the sum/addition(a+b) to the cost 4. Repeat step 3 till min heap size is 1 5. Return The cost
//dry run

// T.C -> O(n.log(n)) && S.C -> O(n)
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        //create a min heap
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        
        //push elems in array into min heap
        for(int i = 0; i < n; i++) {    
            pq.push(arr[i]);
        }
            
        long long cost = 0;
            
        //loop till min heap's size is 1
        while(pq.size() > 1) {
            
            //pick 2 smallest elems 
            long long a = pq.top();
            pq.pop();
                        
            long long b = pq.top();
            pq.pop();
            
            // add 2 smallest elems
            long long sum = a+b;
            
            cost += sum;        //append the addition to the cost
            pq.push(sum);       //push back into min heap
        }
        
        return cost;
    }
};

int main() {

return 0;
}