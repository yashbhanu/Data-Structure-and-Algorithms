#include <iostream>
using namespace std;
 
int main(){
    /*
    int arr[10] = {2,5,6};

    cout<< "address of first memory block is "<<arr<<endl;
    //also
    cout<< "address of first memory block is"<<&arr[0]<<endl;

    cout<< "value at first block" << *arr <<endl;

    cout << "5th "<< *arr + 1 <<endl;       //value at 1st block (i.e 2) + 1 => 3

    cout<< "6th " << *(arr + 1) << endl;     //arr = address of first/0th memory block + 1 => next memory block (i.e address of 1st position) (i.w address of '5') // the whole bracket '*' i.e => value at 1st position = '5'

    cout<< "7th "<< *(arr) + 1 <<endl;

    cout << "8th" << *(arr + 2) <<endl;

   
    int i = 3;
    cout<< i[arr] <<endl;
    
    int temp[10] = {1,2};

    cout<< sizeof(temp) <<endl;     //one block of arr = 4  bits (i.e 10 * 4 => 40)

    cout << "1st" << sizeof(*temp) <<endl;      //value at 0th index of temp (its size = 4)
    cout<< "2nd" << sizeof(&temp) <<endl;       //address at the 0th index (its size = )

    int *ptr = &temp[0];        //address of 0th loc stored in ptr
    cout<< sizeof(ptr) <<endl;      //
    cout<< sizeof(*ptr) <<endl;
    cout<< sizeof(&ptr) <<endl;
    ///////////////////////////////////

   int a[20] = {1,2,3,5};
   cout<< "->" <<&a[0] <<endl;
   cout <<&a <<endl;
   cout <<a <<endl;

   int *p = &a[0];
   cout << p << endl;
   cout << *p << endl;
   cout << "->" <<&p << endl;

   ///////////////////////////////////////////

    int arr1[20];

//ERROR
    // arr = arr + 1;       //arr's value has been mapped with symbol table // now you cannot directly update arr's address

    int *ptr = &arr1[0];
    cout << ptr << endl;
    ptr = ptr + 1;      //we saved arr's first block's address in ptr //now we update ptr and address updates from 0th index to 1st index
    cout << ptr <<endl;
    */


   //CHAR ARRAYS
//    Note : - cout works differently for char arrays and pointers
    
    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    cout << arr <<endl;
    cout << ch <<endl;

    char *c = &ch[0];
    //prints entire string
    cout << c <<endl;

    char temp = 'z';
    //pointer p is pointing to address of 'z' //when we cout p , first it prints z , and the address increements itself till it finds null value (eg lets say address of z = 710, when we cout << p , value at address 710 will be printed (i.e z), noww address will be increemented => 714, 718, 722, and values at these addresses will be printed till it finds a null value) 
    char *p = &temp;

    cout << p << endl;




return 0;
}