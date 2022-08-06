#include <iostream>
using namespace std;

//find square root of a given number //with float part(0.001)
//Given => n (eg 37) //find square root of given number sqrt(37) => 6.082 //sqrt(36) => 6.000
//first find square root in 'int' i.e 6 and then 'float' => 0.082
//use binary search to find 'int' sqrt //use long long int so it doesnt exceed INT_MAX
//if we get a number i.e 37 // use binary search and iterate from '0-36' which is sorted/monotonic 
//set start = 0; set end = n - 1 (i.e 36) //set mid // square the mid (mid*mid) //if its equal to 'n' return mid
//if square > n i.e 18*18 = 324 > n (i.e 37) , update the end and apply BS on left/small part (i.e 0 - 17) //keep on going till you find square < n (i.e 3*3 = 9 > 37)
//if square < n //store it in ans and update start and apply BS on right/greater part i.e (4-7) //do this till you find 6

//find float part
//we give the function the number, precision(how many point we want => (2 = 0.01) , (1 = 0.1), (3 = 0.001)), and integer value found i.e (6) //(36, 3 , 6)
//set factor = 1 //iterate the loop precision times (i.e 3) //factor will be diveded 3 times i.e (0.1,0.01,0.001)
//run loop //check whther the multiplied ans < n => if yes => store it in answer and add factor to j (i.e 6 + 0.1) //dry run to understand properly**


long long int sqrtInteger(int n){
    int s = 0;
    int e = n - 1;
    long long int mid = s + (e - s)/2;

    long long int ans = -1;

    while (s <= e) {
        long long int square = mid*mid;

        if (square == n) {
            return mid;
        }

        if (square < n) {
            ans = mid;
            s = mid + 1;
        }
        //square > n
        else {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

//to get the float value (0.01)
double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;

    for (int i = 0; i < precision; i++)
    {
        factor = factor/10;

        for (double j = ans; j*j<n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
    
}


int main(){

    int n;
    cout<< "Enter a number "<<endl;
    cin >> n;
    
    int tempSol = sqrtInteger(n);
    cout<<"Answer is "<<morePrecision(n, 3, tempSol)<<endl;

return 0;
}
