#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// implement usinf a trie
// you are given an array ["coding", "coder", "codeninjas", "codezen"] // find the longest common prefix(i.e the first common char.s in a string) //  here "cod" is the common prefix
//Approach => check if the root node has single child nodes,if yes then push into ans, if not(i.e has multiple child nodes) then break/stop from loop
// T.C -> O(n*m) , S.C -> O(n*m)
// dry run to understand better

// create trie node
class Trienode {
    public:
        char data;
        Trienode* children[26];
        int childCount;
        bool isTerminal;
    
        Trienode(char ch) {
            data = ch;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            childCount = 0;
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
            root->childCount++;
            root->children[index] = child; // move forward
        }
        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
         insertUtil(root, word);
    }
    
    // func. to check longest common prefix
    void lcp(string str, string &ans) {
        // loop over all characters of string
        for(int i = 0; i < str.length();i++) {
            char ch = str[i];           // take a char from string
            
            // root node has only child node then, push that node's char into ans string
            if(root -> childCount == 1) {
                ans.push_back(ch);
                //move forward & keep checking for other char.s
                int index = ch - 'a';
                root = root -> children[index];
            }
            // has multiple child nodes
            else {
                break;
            }
            
            if(root -> isTerminal) {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');           // create root node as NULL
    
    //insert all strings into tree
    for(int i = 0; i<n; i++) {
        t->insert(arr[i]);
    }
    
    // take 1st string from arr
    string first = arr[0];
    string ans = "";        // ans string
    
    // call func. to find longest common prefix which takes first string of arr & ans string
    t->lcp(first, ans);

    return ans;         //return ans string
}


int main() {

return 0;
}