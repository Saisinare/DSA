class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        vector<bool> visited(V,false);
        int sum = 0 ;
        //{weight,node,parent}
        q.push({0,0,-1});

        while(!q.empty()){
            int wt = q.top()[0];
            int node = q.top()[1];
            int parent = q.top()[2];
            q.pop();
            if(visited[node]) continue;
            sum += wt;
            visited[node] = true;
            for(auto& it:adj[node]){
                int v = it[0];
                int vWt = it[1];
                q.push({vWt,v,node});
            }
        }
        return sum;
    }
};

//Time Complexity : E(log E) where E is the number of edges in the graph.
//Space Complexity : O(V) where V is the number of vertices in the graph.