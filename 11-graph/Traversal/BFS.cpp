#include <bits/stdc++.h>
using namespace std;    

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool> visited(n,false);
        vector<int> ans;
        queue<int> q;
        
        q.push(0);
        visited[0] = true; 
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            int size = adj[front].size();
            for(int i =0;i<size;i++){
                int ele = adj[front][i];
                if(!visited[ele]){
                  q.push(ele);
                  visited[ele] = true;
                } 
            }
            
        }
        return ans;
    }
};

//TC : 
//Outer while loop runs V times inner while loop runs 2E times for undirected graph
//SC : O(V) for queue and visited array