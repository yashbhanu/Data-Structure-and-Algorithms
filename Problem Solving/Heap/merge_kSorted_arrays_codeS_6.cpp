#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        int i;
        int j;
    
    Node(int data, int row, int col) {
        this -> data = data;
        i = row;
        j = col;
    }
};

class compare {
    public:
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
};


#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    
    //step 1 : insert 1st elem of all arrays
    for(int i = 0; i < k; i++) {
        Node* temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
    
    vector<int> ans;
    
    while(!minHeap.empty()) {
        
        Node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();
        
        int i = tmp -> i;
        int j = tmp -> j;
        
        if(j + 1 < kArrays[i].size()) {
            Node* next = new Node(kArrays[i][j+1], i, j + 1);
            minHeap.push(next);
        }    
    }
    return ans;  
}


int main() {

return 0;
}