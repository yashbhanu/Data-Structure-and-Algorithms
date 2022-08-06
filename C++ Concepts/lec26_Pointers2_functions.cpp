#include <iostream>
using namespace std;
 

void print(int *p) {
    cout << *p << endl;
}

void update(int *p) {
    //when we pass a value in a function , it creates a copy of it (refer pass by value)
    //so we increement address of the copy //and no change happens in main func() value
    //p = p + 1;
    //cout << "inside update " << p <<endl;

    //here first it created copy with address //we refering to value at that particular address //now when we created a copy of pointer (eg 710) the address remains the same(ie its copied) // and we increement value stored in that particular address (i.e 710)// hence we it gets updated in main func()  
    *p = *p + 1; 
}

int getSum (int *arr, int n) {

    int sum = 0;
    for (int i = 0; i < n ; i++) {
        sum += arr[i];
    }
    return sum;
}


int main(){

    int value = 5;
    int *p = &value;

    // print(p);

    cout << "before" << *p <<endl;
    update(p);
    cout << "after" << *p <<endl;

    //when we pass an array to a function //behind the scenes the compiler takes the array within a function arg as a pointer only // so no difference if we pass (arr[] OR *arr) => both are same
    int arr[6] = {1,2,4,6,7,8};
    cout << getSum (arr + 3, 3) <<endl;        //as it takes array as a pointer in func arg behind the scenes // if we add '+ 3' to arr (it'll move 3 blocks further and only take 3 values (i.e 6,7,8)) // so we could pass a specific part of array only to the func arg

return 0;
}