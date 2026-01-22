// Do a bfs on every node 
// Insert this node in stack when we complete visit to every node
// Now pop this element out one by one and insert it in the ans vector  
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void topo(int node, vector<int> adj[], vector<bool>& visited,stack<int>& st){
            visited[node] = true;
            for(int ele:adj[node]){
                if(!visited[ele]){
                    visited[ele] = true;
                    topo(ele,adj,visited,st);
                }
            }
            st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> ans;
        vector<bool> visited(V,false);
        stack<int> st;
        for(int i =0;i<V;i++){
            if(!visited[i]){
                topo(i,adj,visited,st);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};
