#include <iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');      // create root node as NULL Node
        }

        void insertUtil(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                root->isTerminal = true;
                return ;
            }

            //assuming that word will be in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if( root -> children[index] != NULL) {
                child = root -> children[index];            //move forward
            }
            else {
                //absent
                child = new TrieNode(word[0]);          //create node
                root -> children[index] = child;        //move forward
            }

            //RECURSION
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                return root ->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root -> children[index] != NULL) {
                child = root -> children[index];        //move forward
            }
            else {
                //absent
                return false;
            }

            //RECURSION
            return searchUtil(child, word.substr(1));

        }

        bool searchWord(string word) {
            return searchUtil(root, word);
        }
};

int main() {

    cout << "hy" << endl;
    Trie *t = new Trie();
    cout << "hy1" << endl;
    t -> insertWord("abcd");
    cout << "hy2" << endl;

    cout << "Present or not " << t ->searchWord("abcd") << endl;
    cout << "hy3" << endl;

return 0;
}