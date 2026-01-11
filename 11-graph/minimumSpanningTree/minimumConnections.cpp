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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DisjointSet ds(n-1);
        int visited = 0;
        int extraEdges = 0;
        for(int i =0 ;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if (ds.find(u,v)){
                extraEdges++;
            }else{
                ds.unionBySize(u,v);
                visited++;
            }
        }
        if(extraEdges>=n-visited-1) return n-visited-1;
        return n-visited-1;
    }
};