#include <iostream>
using namespace std;
#include <vector>

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

//approach 1
//check if linked list is palindrome => 1->2->1 => True // 1->2->3 => False
//create an array and copy all content of LL in array
//pu 2 pointers on array(start and end) // check if values are same , if yes then start++ & end-- till the whole arr is iterated , if no then return false

class Solution{
    public:
    bool checkPalindrome(vector<int> arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        //put 2 pointers and iterate from front and behind
        while(s<=e) {
            if(arr[s] != arr[e]) {      //if values are'nt same the false
                return 0;
            } else {
                s++;e--;        //if values same the moves forward and backward respectively
            }
        }
        return 1;       //return true if whole arr gets iterated
        
    }

    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        Node* temp = head;
        //create an array and copy all content of LL in array
        while(temp != NULL) {
            arr.push_back(temp->data);
            temp = temp -> next;
        }
        return checkPalindrome(arr);
    }
};


int main() {

return 0;
}