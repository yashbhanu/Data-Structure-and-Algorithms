#include <iostream>
using namespace std;

//Tries => Its a data structure which is similar to a tree and used to store and search a specific key from a string // The data structure stores a particular string in the form of nodes(i.e chars) (each nodes is char of the string) connected to each other as children
// Insertion of string // Searching a string // Terminal node -> Represents the last char. in string (eg . 'MAN' . N is terminal node in M) | It doesnt create confusion between "MAN" & "MANY" (i.e It wont return search for "MAN" == true in MANY as "Y" would be the terminal node)

class TrieNode {
    public:
        char data;          // Node shall represent a 'char' of string
        TrieNode* children[26];         // a Node can have total 26 children bcz [a-z] is 26
        bool isTerminal;        // Node will have a flag of terminal node as false OR true

    // constructor to initialize node
    TrieNode(char ch) {
        data = ch;
        //make all possible children of the node NULL initially
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
        TrieNode* root;         // create a pointer root

        Trie() {
            root = new TrieNode('\0');      // create root node as NULL Node
        }

        // func to insert the node which takes root node and word using recursion // solve the case for one char (eg. "A" in "ARM") & other cases will be solved by recursion 
        void insertUtil(TrieNode* root, string word) {
            //base case // if word length is 0 then (i.e word has ended) then assign last node(char) as terminal node && as word khtm ho gya so return back
            if(word.length() == 0) {
                root->isTerminal = true;
                return ;
            }

            //assuming that word will be in CAPS 
            int index = word[0] - 'A';          // find the index in array for that particular char
            TrieNode* child;                    // create a pointer which shall point to the child node 

            //present // first it'll check if that char exists , if YES then simply move forward (& check the other char)
            if( root -> children[index] != NULL) {
                child = root->children[index];            //move forward
            }
            else {
                //absent // if char(i.e node for that char) is absent, then 
                child = new TrieNode(word[0]);          //create node
                root -> children[index] = child;        //move forward
            }

            //RECURSION // give child node(i.e next node downwards) & word(substr(1) bcz 1st word has been processed (i.e "A" in "ARM" is process), cut that "A" and give "RM" in arg)
            insertUtil(child, word.substr(1));
        }

        // function to insert word which takes the word "ARM" as arg and call a func insert util which gives root node created above and word (eg "ARM") in arg
        void insertWord(string word) {
            insertUtil(root, word);
        }

        // to find a word in trie //takes root node and word as arg
        bool searchUtil(TrieNode* root, string word) {

            //base case     // if word has ended that means we are on last node(char) , if its terminal node then it'll return true else false
            if(word.length() == 0) {
                return root ->isTerminal;
            }

            int index = word[0] - 'A';          // find index of the first "char" in word
            TrieNode* child;                    // create a pointer which shall point to the child node 

            //present //if node(char) is present move forward
            if(root -> children[index] != NULL) {
                child = root -> children[index];        //move forward
            }
            else {
                //absent
                return false;
            }

            //RECURSION     // handle for the remaining char.s in word
            return searchUtil(child, word.substr(1));

        }

        //searching // give word
        bool searchWord(string word) {
            return searchUtil(root, word);      // which call another func an gives root node and word
        }
};

int main() {

    Trie *t = new Trie();           // initialized root node as NULL
    t->insertWord("ARM");           // insert word "ARM" in trie
    t->insertWord("MAN");
    cout << "Present or not " << t ->searchWord("ARM") << endl;         // check if "ARM" exists
    cout << "Present or not " << t ->searchWord("MANY") << endl;


return 0;
}