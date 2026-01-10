//kruskal's algorithm 
class DisjointSet {
public:
    vector<int> p,size,rank;

    DisjointSet(int n) {
        p.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        for(int i =0;i<=n;i++){
            p[i] = i;
        }
    }
    int findUPar(int node){
        if(p[node]==node) return node;
        return p[node] = findUPar(p[node]);
    }
    bool find(int u, int v) {
        return findUPar(u) == findUPar(v);
    }

    void unionByRank(int u, int v) {
        int ulP_u = findUPar(u);
        int ulP_v = findUPar(v);

        if(ulP_u == ulP_v){
            return ;
        }else if(rank[ulP_u] < rank[ulP_v]){
            p[ulP_u] = ulP_v;
        }else if(rank[ulP_v] < rank[ulP_u]){
            p[ulP_v] = ulP_u;
        }else{
            p[ulP_u] = ulP_v;
            rank[ulP_v] += rank[ulP_u];
        }
    }

    void unionBySize(int u, int v) {
        int ulP_u = findUPar(u);
        int ulP_v = findUPar(v);

        if(ulP_u == ulP_v){
            return ;
        }else if(size[ulP_u]<size[ulP_v]){
            p[ulP_v] = ulP_u; 
            size[ulP_u] += size[ulP_v];
        }else{
            p[ulP_u] = ulP_v; 
            size[ulP_v] += size[ulP_u];
        }
    }
};

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        //vector<vector<int>> adj[]: array whose each element is vector vector<vector<int>>
        //converting adj list into edges 
        vector<pair<int,pair<int,int>>> edges;
        for(int u =0;u<V;u++){
            for(auto& it : adj[u]){
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt,{u,v}});
            }
        }
        //Sort this edges list by weights
        sort(edges.begin(),edges.end());

        //now start from the first edge and check if u and v are of same componenet if no then add its weight to the final answer 
        DisjointSet ds(V);
        int ans = 0;
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(!ds.find(u,v)){
                ds.unionBySize(u,v);
                ans+=wt;
            }
        }
        return ans;
    }
};
