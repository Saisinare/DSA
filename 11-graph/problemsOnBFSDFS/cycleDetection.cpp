class Solution {
  public:
  
    bool bfs(int start,vector<vector<int>> &adj,vector<bool>& visited) {
        int n = adj.size();
        vector<int> ans;
        queue<pair<int,int>> q;
        visited[start] = true;
        q.push({start,-1});
        
        while(!q.empty()){
            pair<int,int> front = q.front();
            q.pop();
            int node = front.first;
            int parent = front.second;
            int size = adj[node].size();
            for(int i =0;i<size;i++){
                int ele = adj[node][i];
                if(!visited[ele]){
                  q.push({ele,node});
                  visited[ele] = true;
                }else if(ele != parent){
                    return true;
                }
            }
            
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        int m = edges[0].size();
        vector<vector<int>> adj(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);   // undirected
        }
        vector<bool> visited(V,false);

        
        for(int i=1;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                   return true; 
                }
            }
        }
        return false;
    }
};