#include <iostream>
using namespace std;

//given => a string = "test" //find max no. of occurrences of a character //i.e 't' //output => 't'
//create a array of 26 places (a-z) and initialize all 26 positions by 0 // the array is count of characters in the string
//iterate the string // and for every character (if it lies between a-z either lowercase or uppercase) ,subtract it by 'a' i.e (eg ch = 'b' then 'b' - 'a') //you'll get a difference between ascii values
//asci value of a = 097 //asci value of t = 116 // 't' - 'a' = 116-97 = 19 => difference between ascii values //now , arr[number]++ means ,the 19th position/index in the array (i.e t) which was intialized by '0' will ++ i.e '1' // i.e t's count = 1 
//check in alphabet 'a-z' , the 19th position is 't' when started from index '0' //do the same thing for all chars //when 't' will be encountered again in the last its count will be '2'
//get the max value and we'll find max occurences //run another loop till 26 places //set maxi = -1 //check if any greater value exists //if true then store its index in var 'ans' //on 1st iteration // maxi = 1 (i.e e's count) // keep updating maxi
//atlast (maxi = 2 (i.e t's count)) (ans = t's index (i.e 19)) //finalans = add 'a' + ans(i.e t's index '19') //a's ascii value = 097 //hence finalans = 097 + 19 = 116(i.e t's ascii value)
//'t' will be returned as the most occured char 



char getMaxOccChar (string s) {
    //create an array of count of characters
    int arr[26] = {0};

    for (int i=0;i<s.length(); i++) 
    {
        char ch = s[i];
        //lowercase
        int number = 0;
        if (ch >= 'a' && ch <= 'z'){
            number = ch - 'a';
            // cout<<number;  
        }
        else {  //uppercase
            number = ch - 'A';
        }
        arr[number]++;
    }

    //find max occ character
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if(maxi < arr[i] ) {
            ans = i;
            maxi = arr[i];
        }
    }
    char finalAns = 'a' + ans;     
    return finalAns;
}


int main(){

    string s;
    cin>>s;

    char ans = getMaxOccChar(s);
    cout<<ans<<endl;

return 0;
}