class Solution{
public:
 vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        //Reverse all of the outgoing edges to incoming edges 
        vector<int> indegree(V,0);
        vector<vector<int>> revGraph(V);
        for(int i =0;i<V;i++){
            for(auto ele:adj[i]){
                revGraph[ele].push_back(i);
                indegree[i]++;
            }
        }

        //Insert every node who's indegree is zero
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto ele:revGraph[node]){
                    indegree[ele]--;
                    if(indegree[ele]==0) q.push(ele);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};