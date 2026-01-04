class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        vector<bool> visited(V,false);
        vector<int> paths(V,-1);
        //convert this into adjecancy list 
        for(vector<int> arr: edges){
            int u = arr[0];
            int v = arr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //now perform the bfs from the src node but this time with disance 
        queue<pair<int,int>> q;
        q.push({src,0});
        paths[src] = 0;
        visited[src] = true;
        
        while(!q.empty()){
            int ele = q.front().first;
            int dis = q.front().second;
            int size = adj[ele].size();
            q.pop();
            
            for(int i:adj[ele]){
                if(!visited[i]){
                    visited[i] = true;
                    paths[i] = dis+1;
                    q.push({i,dis+1});
                }else if(paths[i] > dis+1) paths[i] = dis+1;
            }
        }
        return paths;
    }
};

/*
Time Complexity : O(V+E)
Space Complexity : O(V) 
*/

// Optimized Code
/*
    we simply need to store the distance in the paths array itself so no need to store it in the queue
*/

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        vector<bool> visited(V,false);
        vector<int> paths(V,-1);
        //convert this into adjecancy list 
        for(vector<int> arr: edges){
            int u = arr[0];
            int v = arr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //now perform the bfs from the src node but this time with disance 
        queue<int> q;
        q.push(src);
        paths[src] = 0;
        visited[src] = true;
        
        while(!q.empty()){
            int ele = q.front();
            int dis = paths[ele];
            int size = adj[ele].size();
            q.pop();
            
            for(int i:adj[ele]){
                if(!visited[i]){
                    visited[i] = true;
                    paths[i] = dis+1;
                    q.push(i);
                }
            }
        }
        return paths;
    }
};
