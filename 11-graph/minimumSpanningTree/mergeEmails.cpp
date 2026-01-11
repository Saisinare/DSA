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
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        //{email->node}
        unordered_map<string,int> mapp;

        for(int i =0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                if(mapp.find(accounts[i][j]) == mapp.end()){
                    mapp[accounts[i][j]] = i;
                }else{
                    ds.unionBySize(i,mapp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> merged(n);
        //Now convert this mapp into the array 
        for(auto& it: mapp){
            string email = it.first;
            int node = it.second;
            int parent = ds.findUPar(node);
            merged[parent].push_back(email); 
        }

        //now sort the emails and add name to front of everyone 
        vector<vector<string>> ans;
        for(int i =0;i<n;i++){
            if(merged[i].size() == 0 ) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(),merged[i].begin(),merged[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};