#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

//Problems => traverse vertically Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
// ref => https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
//Approach => create a horizontal line (like x-axis) (-2 -1 0 1 2 ) to access vertical levels/lines (see img in lec 64) // create levels by level order traversal to traverse through the levels
// so we'll create a map<HL, map<level, vector[nodes]>> => HL represents horizontal line , levels represent tree levels, and vector will have nodes in it => so we created a map that shows for this no. in horizontal line (eg. -1), and for this levels (eg.1) , these are the nodes (eg. 1, 7, 6)
// as we are using level order traversal use queue queue = <[node, [HL, lvl]]> , representts node and its corresponding level and horizontal line no.


class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int,vector<int> >> nodes;          // map<HL, map<level, vector[nodes]>>
        queue<pair<Node*, pair<int,int>>> q;            // queue = <[node, [HL, lvl]]>
        
        vector<int> ans;        // to store elems of traversal
        
        if(root == NULL) return ans;
        
        q.push(make_pair(root, make_pair(0,0)));            // push the root node in queue (corresponding lvl & HL = 0 , 0)
        
        //loop till its empty
        while(!q.empty()) {
            
            //we stored a pair in the queue (Node, [HL, lvl]) // extract dat pair from the queue
            pair<Node*, pair<int,int>> temp = q.front();
            q.pop();
            
            // extract the node from the pair (.first bcz Node is in first place in pair)
            Node* frontNode = temp.first;
            int horizontalDistance = temp.second.first;            //extract horizontalDistance from pair (second pair's first place)
            int level = temp.second.second;                     //extract horizontalDistance from pair (second pair's second place)
            
            //access the vector/array in nodes and for dat corresponding horizontalDistance & level , push the node into array
            nodes[horizontalDistance][level].push_back(frontNode -> data);
            
            //traversal
            //if left exists for the node, then push a pair into queue pair = [node,[Hl - 1, lvl+1]] , as we are traversing on left , hl - 1 bcz are going back/behind in the horizontal line(x-axis)(watch img in lec 64) , and level + 1 bcz level keeps increasing
            if(frontNode -> left)
                q.push(make_pair(frontNode->left, make_pair(horizontalDistance-1, level+1)));
            //if right exists for the node, then push a pair into queue, pair = [node,[Hl - 1, lvl+1]] , as we are traversing on right , hl + 1 bcz are going back/behind in the horizontal line(x-axis)(watch img in lec 64) , and level + 1 bcz level keeps increasing
            if(frontNode -> right)
                q.push(make_pair(frontNode->right, make_pair(horizontalDistance+1, level+1)));
        }
        
        //iterate the map and access the nodes
        //iterate map
        for(auto i: nodes) {
            //inside map, access the 2nd map
            for(auto j: i.second) {
                //inside the second map, access the vector
                for(auto k: j.second) {
                    //push the nodes saved in map's vector in ans vector
                    ans.push_back(k);
                }
            }
        }
        
        return ans;
    }
};


int main() {

return 0;
}