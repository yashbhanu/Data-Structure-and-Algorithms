#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data. 1. The amount of petrol that every petrol pump has.2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between. Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
// N = 4 Petrol = 4 6 7 4 Distance = 6 5 3 5 // now an array with pairs shall be given [{4,6},{6,5},{7,3},{5,4}] // consider 1st pair {4,6} , here petrol = 4 distance = 6 ,(4-6 = -2) , means you cant go to the next block
// so lets start with next {6,5}, (6-5 = 1) , you can go next block with balance petrol = 1 // next block {7,3} , add balance petrol (8-3 = 5) you can go next block with balance petrol = 5 // next block {5,4} , (5+5-4 = 6),you can go next block with balance petrol = 6
// for the first block , we have already calculated the deficit (i.e 2) // so add -2 in balance (i.e 6+(-2) = 4(i.e greater than 0)) // so starting from block ({6,5}), we can complete the whole circular tour // so ans = {6,5} (i.e index '1') 

//Approach
// iterate the array [{4,6},{6,5},{7,3},{5,4}] // balance = add balance + petrol - distance // check if balance is greater than 0 , if yes then keep calculating further till circle isnt complete
// if balance is less than 0, than change the start pt. as next block(start = i+1) and save the deficit (eg. -2) // after iteration is over all over the array , then add the deficit to balance and check if its greater than 0 , if yes then circular round/tour is complete and return the index of start block

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int deficit = 0;
        int balance = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;         //calculate balance
            if(balance < 0) {       //if less than zero
                deficit += balance;     // add balance to deficit
                balance = 0;            //reset balance
                start = i+1;            // change the start block
            }
        }
        
        if(deficit + balance >= 0) {        //after iteration over array is complete , add deficit to balance(which is greater than 0) and check greater than zero
            return start;       //if yes, return start index
        } 
        else {
            return -1;      //circular tour not possible
        }
    }
};


int main() {

return 0;
}