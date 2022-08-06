#include <iostream>
using namespace std;

//codeStudio => will give TLE but understand logic // go to codestudio to understand better
//you are given a stair // you're on the 0th stair // there are total 'n' no. of stairs (eg. 5)
//you have to count Distinct/Different Ways To Climb Stair // For n = 8 stairs, there are total '8' eight ways to climb the stairs i.e. {1,1,1,1,1} , {1,1,1,2} , {1,1,2,1}, {1,2,1,1}, {2,1,1},{2,2,1},{2,1,2} and {2,2,1}. => ans = 8
// Each time you can either climb one step or two steps. //ya toh tum 1 sidhi chadh sakte ho ya 2
//soln
//define base case // if n < 0 (i.e minus) return 0 i.e stairs below 0 cannot exist // of n == 0 i.e if you are on the 0th stair return 1
// in recursion , you have to solve only the 1st case/step, the other cases/steps will be taken by recursion (i.e other function calls)
// so, to reach on a particular stair(eg. stair no. 3) ,either you can take one step ((fn - 1) i.e previous step) OR you can take previous to previous step (i.e 2 step (fn - 2)) // hence, previous(i.e -1) step + 2 steps behind(i.e -2) 
//as we want to find total no. of Distinct ways , we'll use addition
// we have solved case/step 1 // the other steps will be taken care by recursion/repeated func calls 
// dry run to understand deeply

 
int countDistinctWayToClimbStair(long long nStairs)
{
   	//base case
	if (nStairs < 0) return 0;
	
	if (nStairs == 0) return 1;
	
	//recursive call
	int ans = countDistinctWayToClimbStair(nStairs-1) +
		countDistinctWayToClimbStair(nStairs-2);
	
	return ans;
}

int main(){
    long long n;
    cin >> n;

    int ans = countDistinctWayToClimbStair(n);
return 0;
}