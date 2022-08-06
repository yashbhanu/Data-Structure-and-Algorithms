#include <iostream>
using namespace std;

//permutations in string
//given = two strings => s1 = "ab" s2 = "eidbaooo" // permutations of s1 ="ab" => (ab,ba) , check if any of both (ab,ba) are present in s2 = "eidbaooo"
//create a array of 26 places (a-z) and initialize all with '0' //iterate s1 = "ab" and create count for each char (refer lec 22 string max_occurences) 
//now in count1 array [1,1,0,0,0,0,.....0] => a = 1 and b = 1 in their respective alphabetical positions
//traverse s2 till s1.lenght() spaces i.e 2 (e,i)  //do the same above count process for (e,i) //count2 array of 26 (a-z) places => [0,0,0,0,1,0,0,0,1.....0] till 26 places // where count of e = 1, i = 1
//compare count1 (a=1,b=1) and count2 (e=1,i=1) arrays//check if both are same // if yes then true //if not then false //for first traversal count1 (a=1,b=1) and count2 (e=1,i=1) => false
//now change the window (i,d) and compare //traverse whole s2 = "eidbaooo" //add char 'd' by newChar and make its count++ (i.e 1) in count2 array[26] //erase the oldChar (i.e e) from window and make its count-- in count2 array[26]
//now in count2 array => i = 1, d = 1 //compare with count1 array (a = 1, b = 1) //continue till end of s2 //if found s1 then return True else False


bool chechEqual(int a[26], int b[26]) {
    for (int i = 0; i < 26 ; i++) {
    if (a[i] != b[i])
        return 0;
    }
    return 1;
}



bool checkInclusion(string s1, string s2) {
        
        //character count array
        int count1[26] = {0};
        for (int i = 0; i < s1.length();i++) {
            int index = s1[i] - 'a';
            count1[index]++;
        }
        
        //traverse s2 string in window of size s1 length and comapare
        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};
        
        while(i < windowSize && i < s2.length()) {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        if (chechEqual(count1, count2))
            return 1;
        
        //next window process karo
        while (i < s2.length()) {
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;
            
            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;
            
            i++;
            
            if (chechEqual(count1, count2))
            return 1;
        }
        
        return 0;
}

int main(){

    string s1 = "ab";
    string s2 = "eidbaooo";

    cout<<checkInclusion(s1,s2);

return 0;
}