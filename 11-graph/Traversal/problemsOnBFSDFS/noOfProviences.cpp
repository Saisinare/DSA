//brute force and optimal : 
/*
it is nothing but a simple connected componenet problem the problem is only that in the connected component problem their was adjacency list given but in this problem we are given a matrix so to overcome this problem we need to convert this matrix into list  
*/
class Solution {
public:
    void bfs(vector<vector<int>> &adj,int node,vector<bool>& visited) {
        int n = adj.size();
        queue<int> q;
        
        q.push(node);
        visited[node] = true; 
        
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            int size = adj[front].size();
            for(int i =0;i<size;i++){
                int ele = adj[front][i];
                if(!visited[ele]){
                  q.push(ele);
                  visited[ele] = true;
                } 
            }
            
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n,vector<int>(n,0));
        vector<bool> vis(n,false);
        for(int i = 0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    vis[i] = true;
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        for(int i =0;i<isConnected.size();i++){
            if(!visited[i]){
                bfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};

//TC: N^2 + 2E 
//SC: N 