#include <iostream>
using namespace std;

void reverse(char arr[], int n) {
    int s = 0, e = n - 1;
    while (s<e) {
        swap(arr[s++], arr[e--]);
    }
}


//in a character Array , value just after last char value is stored as null (\0) i.e [y,a,s,h,\0,......]
//iterate the whole character array starting from 0 till null value 

int getLength(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main(){

    char name[20];

    cout<<"Enter your name "<<endl;

    cin>> name;

    cout<<"Your name is "<<name<<endl;

    int n = getLength(name);

    cout<<"Length of string is "<<n<<endl;

    reverse(name, n);

    cout<<"reverse of str is "<< name <<endl;

return 0;
}