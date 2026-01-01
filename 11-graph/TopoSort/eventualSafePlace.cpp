class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse all of indegree of graph to indegree 
        int n = graph.size();
        vector<vector<int>> reversedGraph(n); 
        vector<int> indegree(n,0); 

        for(int i =0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                reversedGraph[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        for(int i =0;i<indegree.size();i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){

            int front = q.front();
            q.pop();
            ans.push_back(front);

            int size = reversedGraph[front].size();

            for(int i=0;i<size;i++){
                if(indegree[reversedGraph[front][i]] > 0 ) indegree[reversedGraph[front][i]]--;
                if(indegree[reversedGraph[front][i]] == 0 ) q.push(reversedGraph[front][i]);
            }

        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};