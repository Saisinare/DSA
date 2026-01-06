//This problem can be solved using the reverse dijkstra's algorithm 
using P = pair<int,int>;
using T = pair<int,pair<int,int>>;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //effort to reach node {effor,node}
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<T,vector<T>,greater<T>> q;
        vector<vector<int>> efforts(m,vector<int>(n,1e9));   
        efforts[m-1][n-1] = 0;   
        q.push({0,{m-1,n-1}});
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        while(!q.empty()){
            int node = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            if(node > efforts[i][j]) continue;
            for(int k =0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<m && nj>=0 && nj<n){
                    int newEfforts = max(
                        efforts[i][j],
                        abs(heights[i][j] -  heights[ni][nj]) 
                    );
                    
                    if(newEfforts < efforts[ni][nj]){
                        efforts[ni][nj] = newEfforts;
                        q.push({newEfforts,{ni,nj}});
                    }
                }
            }
        }
        return efforts[0][0];
    }
};