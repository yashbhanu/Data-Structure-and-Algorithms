#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//perform on leetcode
// string compression => given = chars = ["a","a","b","b","c","c","c"] //we need to count values of each character and show it => OP => ["a","2","b","2","c","3"]
//the count of chars should be inserted into the vector //if there is only one char => ["a","b","b","c","c","c"] (eg ."a") //then dont display its count // show only the char => OP => ["a","b","2","c","3"]
//the changes should be done in existing vector/array and new array must not be created // return the length of the vector => ["a","2","b","2","c","3"] here length = 6 i.e return '6' as OP
//approach
//traverse the vector by i  and n //initialize ansIndex = 0 // while (i<n) , j = i + 1 i.e j =0+1 = 1 (i.e secondelem "a") //while j less than n and chars[i] == chars[j] i.e "a" = "a" , j++ 
//now j = 2nd index i.e "b" //out of the while loop //store old charcter i.e "a" //chars[ansIndex++] = chars[i] means chars[0] = chars[0] i.e "a" stored in chars//move ansIndex++ //count = j - 1 i.e 2- 0 = 2
//if count(i.e 2) > 1 => true then ,  //converting count to a single digit and saving it //convert count into string // iterate the string // chars[ansIndex++] = ch means //chars[1] = ch(i.e "2") //move ansIndex++
//now chars vector = ["a", "2"] // //moving to different character i.e (i = j) i.e (i = 2 index (i.e "b")) //continue above approach to get whole OP vector i.e ["a","2","b","2","c","3"]
//we need to return length of newly created vector//return ansIndex at the end bcz ansIndex will be 6 in the end after the whole vector is iterated //



int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();
        
        while (i < n) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }
            
            //now, when a new elem is encountered or the vector is traversed completely
            
            //store old char
            chars[ansIndex++] = chars[i];
            
            int count = j - i;
            
            if (count > 1){
                //converting counting to a single digit and saving it
                string cnt = to_string(count);
                for(char ch:cnt) {
                    chars[ansIndex++] = ch;
                }
            }
            //moving to different character
            i = j;
        }
        return ansIndex;
} 


int main(){

    // vector<char> a = {"a","a","b","b","c","c","c"};

    // cout<<compress(a)<<endl;

return 0;
}