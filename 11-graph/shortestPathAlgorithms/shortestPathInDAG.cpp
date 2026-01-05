// User function Template for C++
class Solution {
  public:
    vector<int> topoSort(vector<vector<pair<int,int>>>& adj,int V){
        vector<int> indegree(V,0);
        vector<int> ans;
        for(auto v:adj){
            for(auto node:v){
                indegree[node.first]++;
            }
        }
        
        queue<int> q;
        int n = indegree.size();
        for(int i =0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for(auto &i :adj[front]){
                indegree[i.first]--;
                if(indegree[i.first]==0) q.push(i.first);
            }
        }
        return ans;
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        //Create adjecency list with edges and weight 
        vector<vector<pair<int,int>>> adj(V);
        for(int i =0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            
            adj[u].push_back({v,weight});
        }
        // apply the topo sort on this adj using kahan's algorithm 
        vector<int> topo = topoSort(adj,V);
        
        //calculate the distance for every node from give source node
        vector<int> dis(V,INT_MAX);
        dis[0] = 0;
        
        for(int u: topo){
            if(dis[u] != INT_MAX){
            for(auto& it:adj[u]){
                int node = it.first;
                int wt = it.second;
                
                if(dis[u]+wt < dis[node]){
                    dis[node] = dis[u]+wt;
                }
            }
        }
        }
            for(int i = 0; i < V; i++){
        if(dis[i] == INT_MAX) dis[i] = -1;
    }
        return dis;
        
    }
};
