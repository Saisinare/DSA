class Solution {
  public:
    void dfs(int V, vector<vector<int>>& graph,int node,vector<bool>& visited,stack<int>& st){
        // try to push node here in stack (get unexpected output)  
        // why ?? 
        // if we insert it here the order where we must insert u before v when u->v 
        // first i think that i will follow this preorder insertion approach and 
        // then reverse the final answer which will produce a correct order 
        // but reversal cannot correct early insertion violation 
        /*
        e.g.:  
            1 → 0
            2 → 0
        proper order: 
            1 2 0
            2 1 0
        
        what actully happens?  
        dfs(0):
         push(0)
        
        dfs(1):
          push(1)
        
        dfs(2):
          push(2)

        2
        1   
        0
        
        ans = 0 1 2 which is wrong 

        
        */
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