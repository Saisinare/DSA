class Solution {
public:
    void dfs(int node, int parent, int& counter,vector<bool>& vis,vector<int>& dis,vector<int>& low, vector<vector<int>>& adj,vector<vector<int>>& ans){
        vis[node] = true;
        dis[node] = low[node] = counter;
        counter++;

        for(int i =0;i<adj[node].size();i++){
            int child = adj[node][i];
            if(child == parent) continue;
            
            if(!vis[child]){
                dfs(child,node,counter,vis,dis,low,adj,ans);

                low[node] = min(low[node],low[child]);

                if(low[child] > dis[node]){
                    ans.push_back({node,child});
                }

            }else{
                low[node] = min(low[node],dis[child]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //n is number of vertices in graph 
        //convert edges to adj list 
        vector<bool> vis(n,false);
        vector<int> dis(n);
        vector<int> low(n);
        vector<vector<int>> adj(n);
        vector<vector<int>> ans;
        for(auto& it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int counter = 0 ;
        dfs(0,-1,counter,vis,dis,low,adj,ans);

        return ans;
    }
};

// Time complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
// Space complexity: O(V) for the auxiliary data structures used in the DFS traversal.