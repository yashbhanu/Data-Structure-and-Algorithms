#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Problem => You are given an array => ["cod" ,"coding", "codding", "code", "coly"] && queryStr i.e ("coding")
// you need to give suggestion of all words with prefixes in queryStr(i.e "coding") // In "coding" , I type "c" all 5 suggestion shall come -> ["cod" ,"coding", "codding", "code", "coly"]
// if I type "co" again all 5 suggestions shall come -> ["cod" ,"coding", "codding", "code", "coly"] // if I type "cod" , 4 suggestions shall come ["cod" ,"coding", "codding", "code"]
// If I type "codi" only 1 suggestion ["coding"] and so on for "codin" , "coding" // find out all possible suggestion for each and every prefix typed and push it into 2D array

//Approach => push all the string/words in array into a trie // loop over the string and printSuggestions for every keyword typed in the string & push it into 2D array
// dry run to understand better

class Trienode {
    public:
        char data;
        Trienode* children[26];
        bool isTerminal;
    
        Trienode(char ch) {
            data = ch;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

// create a whole trie
class Trie {
    public:

        Trienode* root;
        //initialize root node    
        Trie(char ch) {
            root = new Trienode(ch);
        }
    
    // to insert char(i.e nodes) into trie
    void insertUtil(Trienode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        Trienode *child;           
        if (root->children[index] != NULL)
        {
            child = root->children[index]; 
        }
        else
        {
            child = new Trienode(word[0]); // create node
            root->children[index] = child; // move forward
        }
        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
         insertUtil(root, word);
    }

    // find suggestions possible for a particular prefix
    void printSuggestions(Trienode* curr,vector<string> &temp,string prefix) {
        // if curr node is terminal node i.e we have all the char.s in prefix which forms a possible suggestion(i.e string)
        if(curr -> isTerminal) {
            temp.push_back(prefix);         // push that suggestion in the array
        }

        // loop over from a-z & check for the child of the curr node (i.e if "c" is ch then check for possible childen nodes of "c" -> i.e "o")
        for(char ch = 'a'; ch <= 'z'; ch++) {
            Trienode* next = curr -> children[ch - 'a'];            // next shall point to curr node's child (i.e "o")

            // shall check from a-m (i.e till o) // as soon as "o" is found , it'll go inside if cond.
            if(next != NULL) {
                // push back ch (i.e "o") in prefix // now prefix is "co"
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);       // find all suggestions for "co" // go on till "cod" , "codi" ..."coding" using RECURSION
                prefix.pop_back();              // BACKTRACKING // pop back char.s while coming back from tree(dry run to understand)
            }
        }
    }

    vector<vector <string> > getSuggestions(string str) {
        Trienode* prev = root;          // prev pointer pointing to root node
        vector<vector<string> > output;         // 2D ans array

        string prefix = "";         // string prefix which shall store all the keywords of the string and find possible suggestions -> i.e "c", "co", "cod", "codi"...etc

        //loop over the string
        for(int i = 0; i < str.length(); i++) {
            char lastch = str[i];           // take a single char . (initially "c")

            prefix.push_back(lastch);       // push into prefic (i.e c)

            //check for lastch in trie      // check if that char "c" exists in trie
            Trienode* curr = prev -> children[lastch - 'a'];

            //not found | doesnt exist 
            if(curr == NULL) {  
                break;      // then exit loop
            }

            //if found  // "c" exists
            vector<string> temp;        // create an array which shall store all possible suggestion i.e ["cod" ,"coding", "codding", "code", "coly"] which shall be pushed later in 2D array
            printSuggestions(curr, temp, prefix);       // find all possible suggestion for that particular prefix

            output.push_back(temp);         // push those suggestions in 2D array
            temp.clear();                   // clear the temp array for the storage of suggestions of next prefix value (eg. "co")
            prev = curr;                    // move forward in trie // curr node was "c" initially , now it'll be "o".......so on.....etc
        }

        return output;              // return 2D array as ans
    }

    
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    
    //creation of trie
    Trie *t = new Trie('\0');
    
    //insert all elements in trie
    for (int i = 0; i < contactList.size(); i++) {
      string str = contactList[i];
      t->insert(str);
    }

    // get suggestion for the given query string (i.e "coding")
    return t->getSuggestions(queryStr);
    
}

int main() {

return 0;
}