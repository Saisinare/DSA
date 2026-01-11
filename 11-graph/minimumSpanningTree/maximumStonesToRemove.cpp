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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        int n = stones.size();
        for(auto& it:stones){
             maxRow = max(maxRow,it[0]);
             maxCol = max(maxCol,it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);

        unordered_map<int,int> mapp;

        for(auto& it: stones){
            int row = it[0];
            int col = it[1] + maxRow +1 ;
            ds.unionBySize(row,col);
            mapp[row] = 1;
            mapp[col] = 1;
        }

        int count = 0 ;
        //find the number of componenets 
        for(auto& it: mapp){
            if(ds.findUPar(it.first) == it.first){
                count ++;
            }
        }
        return n - count ;
    }
};