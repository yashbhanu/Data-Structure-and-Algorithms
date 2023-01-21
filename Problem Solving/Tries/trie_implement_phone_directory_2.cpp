#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Problem => You are given an array => ["cod" ,"coding", "codding", "code", "coly"] && queryStr i.e ("coding")
// you need to give suggestion of all words with prefixes in queryStr(i.e "coding") // In "coding" , I type "c" all 5 suggestion shall come -> ["cod" ,"coding", "codding", "code", "coly"]
// if I type "co" again all 5 suggestions shall come -> ["cod" ,"coding", "codding", "code", "coly"] // if I type "cod" , 4 suggestions shall come ["cod" ,"coding", "codding", "code"]
// If I type "codi" only 1 suggestion ["coding"] and so on for "codin" , "coding" // find out all possible suggestion for each and every prefix typed and push it into 2D array


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

    void printSuggestions(Trienode* curr,vector<string> &temp,string prefix) {
        if(curr -> isTerminal) {
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            Trienode* next = curr -> children[ch - 'a'];

            if(next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector <string> > getSuggestions(string str) {
        Trienode* prev = root;
        vector<vector<string> > output;

        string prefix = "";

        for(int i = 0; i < str.length(); i++) {
            char lastch = str[i];

            prefix.push_back(lastch);

            //check for lastch in trie
            Trienode* curr = prev -> children[lastch - 'a'];

            //not found | doesnt exist
            if(curr == NULL) {
                break;
            }

            //if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
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

    return t->getSuggestions(queryStr);
    
}

int main() {

return 0;
}