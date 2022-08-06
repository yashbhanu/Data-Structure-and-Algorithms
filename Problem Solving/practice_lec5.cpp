#include <iostream>
using namespace std;
 
int main(){

    // problem 1
    // for (int i = 0; i<=5; i++)
    // {
    //     cout<< i << " ";
    //     i++;
    // }


    // problem 2
    // for (int i = 0; i <=5; i--)
    // {
    //     //infinite loop
    //     cout<< i << " ";
    //     i++; 
    // }

    // problem 3
    // for (int i = 0; i <= 15; i+=2)
    // {
    //     cout<<i<<" ";
    

    // if(i&1) {
    //     cout<<"print";
    //     continue;
    // }

    // i++;
    // }


    //problem 4
    // for (int i = 0; i<5; i++)
    // {
    //     for (int j = i; j <=5; j++)
    //     {
    //         cout<<i<<" "<<j<<endl;
    //     }
        
    // }

    //problem 5
    for (int i = 0; i<5; i++)
    {
        for (int j = i; j <=5; j++)
        {
            if(i+j == 10) {
                break;
            }
            cout<<i<<" "<<j<<endl;
        }
        
    }
    
    
    
return 0;
}