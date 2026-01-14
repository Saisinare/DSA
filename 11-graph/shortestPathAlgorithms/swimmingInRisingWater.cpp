//brute force 
class Solution {
public: 
    bool dfs(int t,vector<vector<int>>& grid,int n){
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        q.push({0,0});
        vis[0][0] = true;
        vector<pair<int,int>> dxy = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            if(r >= n-1 && c >= n-1) return true;

            for(auto& it:dxy){
                int nr = r + it.first;
                int nc = c + it.second;
                if(nr>=0 && nr<n && nc>=0 && nc <n && !vis[nr][nc] && grid[nr][nc] <= t ){
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        //find the maximum height 
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                maxi = max(maxi,grid[i][j]);
            }
        }
        for(int t =0;t<maxi;t++){
            if(grid[0][0] > t || grid[n-1][n-1] > t) continue; 
            if(dfs(t,grid,n)) return t; 
        }
        return maxi;
    }
};

// The total time complexity is determined by the nested nature of the search and the traversal.

// Time Complexity : Outer loop n^2 dfs requires n^2 inside this loop hence n^4 
// Space Complexity : O(N^2) for visited array and queue in worst case can have all nodes

//most optimal solution 
using P = pair<int,pair<int,int>>;
class Solution {
public: 
    int swimInWater(vector<vector<int>>& grid) {
        //create a priority queue {height,x,y}
        //push all of the terrian till maximum height 
        //it will automatically sort it in the lowest at top by height 
        //the basic idea is we have to start connecting the smallest nearest neighbors as possible 
        //connect the componenet which is not connected using disjoint set 
        //at the end if the start and end is connected then return the top elements height 
        int n = grid.size();

        //this is not constructor so don't use () use <> instead
        priority_queue<P,vector<P>,greater<P>> q;
        q.push({grid[0][0],{0,0}});
        //now dijkstra's style algorithm on this 
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[0][0] = true;

        while(!q.empty()){
            auto it = q.top();
            int ele = it.first;
            int x = it.second.first;
            int y = it.second.second;
            q.pop();
            if(x == n-1 && y == n-1) return ele;
            for(int i =0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({max(ele,grid[nx][ny]),{nx,ny}});
                }
            }
        }
        return INT_MAX;
    }
};

//Time Complexity : Nodes = N^2 work per node log n^2 as every push pop operation requires log k in this case k = n^2 so we requires log n^2 operations so final time complexity will be 
// n^2 * log n^2
//Space Complexity : O(N^2) for visited array and priority queue in worst case can have all nodes

//this can also solved by the (binary search on bfs dfs / kruscal's algorithm with disjoint set union)