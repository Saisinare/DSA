#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void traverse(vector<vector<int>>& adj,vector<bool>& visited,int i,vector<int>& ans){
        for(int it: adj[i]){
            if(!visited[it]){
                visited[it] = true;
                ans.push_back(it);
                traverse(adj,visited,it,ans);
            }
        }
        return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<bool>visited (adj.size(),false);
        vector<int> ans;
        ans.push_back(0);
        visited[0] = true;
        traverse(adj,visited,0,ans);
        return ans;
    }
};

//TC: O(V + 2*E) V = processing time (you are visiting every node) E = you are traversing through every edge twice in undirected graph
//SC: O(V)
