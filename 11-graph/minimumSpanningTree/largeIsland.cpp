
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

        void unionBySize(int u, int v) {
            int ulP_u = findUPar(u);
            int ulP_v = findUPar(v);

            if(ulP_u == ulP_v){
                return ;
            }else if(size[ulP_u]<size[ulP_v]){
                p[ulP_u] = ulP_v; 
                size[ulP_v] += size[ulP_u];
            }else{
                p[ulP_v] = ulP_u; 
                size[ulP_u] += size[ulP_v];
            }
        }
    };
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        bool isOneExist = false;

        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                int node = i * n + j;
                if(grid[i][j] == 1){
                    isOneExist = true;
                    for(int k =0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        int adjNode = ni * n + nj;
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] == 1 && !ds.find(node,adjNode)){
                            ds.unionBySize(adjNode,node);
                        }
                    }
                }
            }
        }
        if(!isOneExist) return 1;
        bool isZeroExist = false;
        int maxi = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                int node = i * n + j;
                if(grid[i][j] == 0){
                isZeroExist = true;

                    int temp = 1;
                    unordered_set<int> sett;
                    for(int k =0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        int adjNode = ni * n + nj;
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] == 1){
                            int parent = ds.findUPar(adjNode);
                            sett.insert(parent);  
                        }
                    }
                    for(auto&it : sett) temp+=ds.size[it];
                    maxi = max(maxi,temp);
                }
            }
        }
        if(!isZeroExist) return n*n;
        return maxi;
    }
};