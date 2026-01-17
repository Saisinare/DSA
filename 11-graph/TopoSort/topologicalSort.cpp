class Solution {
  public:
    void dfs(int V, vector<vector<int>>& graph,int node,vector<bool>& visited,stack<int>& st){
        visited[node] = true;

        for(auto& it: graph[node]){
            if(!visited[it]){
                dfs(V,graph,it,visited,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> graph(V);
        vector<bool> visited(V,false);
        stack<int> st;
        
        for(auto& i: edges){
            graph[i[0]].push_back(i[1]);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(V,graph,i,visited,st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};