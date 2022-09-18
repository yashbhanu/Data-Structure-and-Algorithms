#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

//Problem => bottom view of binary tree (view diagram to understand better) ref => https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
//traverse the tree from its bottom view // some of the nodes may come in between the bottom view of the other nodes, hence they wont be visible and wont be printed

//Approach =>  create a horizontal line (like x-axis) (-2 -1 0 1 2 ) to access vertical levels/lines (see img in lec 64)
// so we'll create a map<HL, node> => HL represents horizontal line/distance , and  will have nodes in it => so we created a map that shows for this no. in horizontal line (eg. -1) this is the nodes (eg. 1) // a particular mapping will have only one node, and not multiple bcz other nodes will be hidden behind the bottom view of the bottommost node
// as we are using level order traversal use queue queue = <[node, HL]> , representts node and its corresponding horizontal line/distance no.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;        // to store elems of traversal
        if(root == NULL) return ans;
        
        map<int, int> bottomNode;          // map<HL,nodes>
        queue<pair<Node*, int> > q;         // queue<[node, HL]>
        

        q.push(make_pair(root, 0));             // push the root node in queue (corresponding HL = 0)
        
        //loop till queue is empty
        while(!q.empty()) {
            //we stored a pair in the queue <[node, HL]> // extract dat pair from the queue
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;       //extract the node from the queue
            int horizontalDistance = temp.second;                     //extract the horizontal distance
            
            //it will overwrite the node for a corresponding horizontalDistance if is already inserted (eg .10)
            bottomNode[horizontalDistance] = frontNode -> data;            //insert node for the horizontal distance mapping // it'll overwrite if some mapping already exists
            
            //traversal
            //if left exists for the node, then push a pair into queue pair = [node,[Hl - 1] , as we are traversing on left , hl - 1 bcz are going back/behind in the horizontal line(x-axis)(watch img in lec 64) 
            if(frontNode -> left)
                q.push(make_pair(frontNode->left, horizontalDistance-1));
            //if right exists for the node, then push a pair into queue, pair = [node,[Hl - 1] , as we are traversing on right , hl + 1 bcz are going back/behind in the horizontal line(x-axis)(watch img in lec 64) 
            if(frontNode -> right)
                q.push(make_pair(frontNode->right, horizontalDistance+1));
                
        }
        
        //loop over the vector in map
        for(auto i: bottomNode) {
            ans.push_back(i.second);        // and push the ans of dat vector/array in ans vector/array
        }
        return ans;
    }
};

int main() {

return 0;
}