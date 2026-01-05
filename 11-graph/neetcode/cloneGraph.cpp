/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//do simple DFS and create new nodes with this values 
/*
    1. Maintain a map for mapping original->cloned nodes 
    2. Run dfs on node given if its available on the map then return its clone 
    3. if not then just create a new node with all of the nodes cloned 
*/
class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*>& mapp){
        if(!node) return nullptr;
        if(mapp.find(node) != mapp.end()) return mapp[node];

        Node* clone = new Node(node->val);
        //map before cloning its neighbors if not then it will cause infinite loop condition 

        mapp[node] = clone;
        for(auto& n:node->neighbors){
            clone->neighbors.push_back(dfs(n,mapp));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*,Node*> mapp;
        dfs(node,mapp);
        return mapp[node];
    }
};

//Time Complexity: V+2E -> as in undirected graph each edge is traversed twice O(V+E) for standard form 
//Space Complexity: 
/*
    1. space used by extra data structures  : V (mapp required)
    2. recursive stack space                : V (in worst case)
    3. output space                         : V+E (for cloned graph)

    overall: O(V) excluding output
*/