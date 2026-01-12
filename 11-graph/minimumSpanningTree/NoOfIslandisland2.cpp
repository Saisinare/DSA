
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
    class Solution{
    public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){
            DisjointSet ds(m*n);
            vector<vector<int>> grid(n,vector<int>(m,0));
            int count =0;
            vector<int> ans;

            vector<int> dy = {1,-1,0,0};
            vector<int> dx = {0,0,1,-1};
            
            for(auto& it:A){
                int r = it[0], c =it[1];
                
                if(grid[r][c] == 1){
                    ans.push_back(count);
                    continue;
                }
                count++;
                int node = r * m + c;

                grid[r][c] = 1;
                for(int i =0;i<4;i++){
                    int nr = r + dy[i];
                    int nc = c + dx[i];
                    int adjNode = nr * m + nc;
                    if(nr >=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        if(!ds.find(adjNode,node)){
                            ds.unionBySize(adjNode,node);
                            count--;
                        }
                    }
                }
                ans.push_back(count);          
            }
            return ans;
        }
    };