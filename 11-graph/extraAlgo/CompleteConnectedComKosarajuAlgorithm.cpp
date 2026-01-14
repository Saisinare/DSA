class Solution{
public:

    void dfs(int node,vector<bool>& visited,vector<int> adj[],stack<int>& sett){
        visited[node] = true;

        for(int i =0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs(adj[node][i],visited,adj,sett);
            }
        }

        sett.push(node);
    }

    void dfsWithoutSet(int node,vector<bool>& visited,vector<vector<int>>& adj){
        visited[node] = true;

        for(int i =0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfsWithoutSet(adj[node][i],visited,adj);
            }
        }

    }

    int kosaraju(int V, vector<int> adj[]){
        stack<int> st; 
        vector<bool> visited(V,false);

        //store all of the nodes according to their dfs order 

        for(int i = 0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        
        //reverse the edges between every node in graph 
        vector<vector<int>> graph(V);

        for(int i =0;i<V;i++){
            visited[i] = false; 
            for(int v : adj[i]){
                graph[v].push_back(i);
            }
        }

        //Now pop out the sett elements one by one and count the number of strongly connected components  
        int count = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!visited[top]){
                count++;
                dfsWithoutSet(top,visited,graph);
            }
        }
        return count;
    }


};

// Space : (V + V+E + V +V ) = O(V+E)  
// Time : (V+E + V+E + V) = O(V+E)
