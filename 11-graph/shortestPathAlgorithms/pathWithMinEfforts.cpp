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
// Reverse Dijkstra is the same as Dijkstra’s algorithm, but it starts from the destination instead of the source.
// It works here because the grid is undirected.

// Each cell stores the minimum effort needed to reach the destination, where effort means the maximum height difference on the path.

// When moving to a neighbor, the new effort is calculated as:

// newEffort = max(currentEffort, heightDifference)


// A min-priority queue is used to always expand the cell with the smallest effort first.

// Complexity

// Time: O(n × m × log(n × m))

// Space: O(n × m)


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        int n=heights.size();
        int m=heights[0].size();
        vector<int>drow={-1,1,0,0};
        vector<int>dcol={0,0,-1,1};

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        pq.push({0,{0,0}});dist[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int diff=it.first;
            int r=it.second.first,c=it.second.second;
            if(r==n-1 && c==m-1) return dist[r][c];

            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];

                if(ncol>=0 && nrow>=0 && ncol<m && nrow<n){
                    int newEff=max(abs(heights[r][c]-heights[nrow][ncol]),diff);
                    if(newEff<dist[nrow][ncol]){
                        pq.push({newEff,{nrow,ncol}});
                        dist[nrow][ncol]=newEff;
                    }
                }
            }
        }
        return dist[n-1][m-1];
        
    }
}; //normal dijkstra 