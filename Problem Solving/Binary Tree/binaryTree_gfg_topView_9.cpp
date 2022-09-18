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

//Problem => top view of binary tree (view diagram to understand better) ref => https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
//traverse the tree from its top view // some of the nodes may come in between the top view of the other nodes, hence the wont be visible and wont be printed
// OP in eg => 4 2 1 3 7 , 5 6 wont be visisble as they get hidden under 1

//Approach =>  create a horizontal line (like x-axis) (-2 -1 0 1 2 ) to access vertical levels/lines (see img in lec 64)
// so we'll create a map<HL, node> => HL represents horizontal line/distance , and  will have nodes in it => so we created a map that shows for this no. in horizontal line (eg. -1) this is the nodes (eg. 1) // a particular mapping will have only one node, and not multiple bcz other nodes will be hidden behind the top view of the toppest node
// as we are using level order traversal use queue queue = <[node, HL]> , representts node and its corresponding horizontal line/distance no.


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;        // to store elems of traversal
        if(root == NULL) return ans;
        
        map<int, int> topNode;          // map<HL,nodes>
        queue<pair<Node*, int> > q;         // queue<[node, HL]>
        

        q.push(make_pair(root, 0));             // push the root node in queue (corresponding HL = 0)
        
        //loop till queue is empty
        while(!q.empty()) {
            //we stored a pair in the queue <[node, HL]> // extract dat pair from the queue
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;       //extract the node from the queue
            int horizontalDistance = temp.second;                     //extract the horizontal distance
            
            //if one value is present for a HD, do nothing  // the below code states => `topNode.find(horizontalDistance) yeh uss horizontalDistance ko topNode(mapping) main dhundhta hai, aur agar nahi milta toh uska output topNode.end() ke eqaul hota hai, hence niche uss corresponding horizontalDistance ke liye node insert karo && agar woh corresponding horizontalDistance mil jata h toh uski value topNode.end() ke equal nahi hogi and if stat. false hojayega and kuch nhi karega`
            if(topNode.find(horizontalDistance) == topNode.end()) {
                topNode[horizontalDistance] = frontNode -> data;            //insert node for the horizontal distance mapping if it doesn't exist already
            }
            
            //traversal
            //if left exists for the node, then push a pair into queue pair = [node,[Hl - 1] , as we are traversing on left , hl - 1 bcz are going back/behind in the horizontal line(x-axis)(watch img in lec 64) 
            if(frontNode -> left)
                q.push(make_pair(frontNode->left, horizontalDistance-1));
            //if right exists for the node, then push a pair into queue, pair = [node,[Hl - 1] , as we are traversing on right , hl + 1 bcz are going back/behind in the horizontal line(x-axis)(watch img in lec 64) 
            if(frontNode -> right)
                q.push(make_pair(frontNode->right, horizontalDistance+1));
                
        }
        
        //loop over the vector in map
        for(auto i: topNode) {
            ans.push_back(i.second);        // and push the ans of dat vector/array in ans vector/array
        }
        return ans;
        
    }

};


int main() {

return 0;
}