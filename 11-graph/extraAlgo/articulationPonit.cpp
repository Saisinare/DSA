// User function Template for C++
class Solution{
    
public: 
        void dfs(int node, int parent, int& counter,vector<bool>& vis,vector<int>& dis,vector<int>& low, vector<int> adj[],vector<bool>& isAP){
        vis[node] = true;
        dis[node] = low[node] = counter;
        counter++;
        int childCount = 0 ;
        for(int i =0;i<adj[node].size();i++){
            int child = adj[node][i];
            if(child == parent) continue;
            
            if(!vis[child]){
                childCount++;
                dfs(child,node,counter,vis,dis,low,adj,isAP);

                low[node] = min(low[node],low[child]);
                
                if(parent!=-1 && low[child] >= dis[node]){
                    isAP[node] = true;
                }

            }else{
                low[node] = min(low[node],dis[child]);
            }
        }
        if(parent == -1 && childCount > 1) isAP[node] = true;
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        //n is number of vertices in graph 
        //convert edges to adj list 
        int n = V;
        vector<bool> vis(n,false);
        vector<int> dis(n);
        vector<int> low(n);
        
        vector<int> ans;
        vector<bool> isAP(n,false);
        int counter = 0 ;
        dfs(0,-1,counter,vis,dis,low,adj,isAP);
        for(int i =0 ;i<isAP.size();i++){
            if(isAP[i]) ans.push_back(i);
        }
        return ans.empty() ? vector<int>{-1} : ans;
    }
};