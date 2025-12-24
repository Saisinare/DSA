class Solution {
public:

    void bfs(vector<vector<int>>& grid,queue<pair<int,int>>& q,vector<vector<bool>>& visited,vector<int>& dy,vector<int>& dx){
        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty()){
                auto front = q.front();
                q.pop();
                int i = front.first;
                int j = front.second;


                for(int l =0;l<4;l++){
                    int ni = i+dy[l];
                    int nj = j+dx[l];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1 && !visited[ni][nj]){
                        q.push({ni,nj});
                        visited[ni][nj] = true;
                    }
            }         
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        //first and last row 
        for(int j =0;j<n;j++){
            if(!visited[0][j] && grid[0][j] == 1){
                q.push({0,j});
                visited[0][j] = true;
            }
            if(!visited[m-1][j] && grid[m-1][j] == 1){
                q.push({m-1,j});
                visited[m-1][j] = true;
            }
        }

        //first and last column
        for(int i =0;i<m;i++){
            if(!visited[i][0] && grid[i][0] == 1){
                q.push({i,0});
                visited[i][0] = true;
            }
            if(!visited[i][n-1] && grid[i][n-1] == 1){
                q.push({i,n-1});
                visited[i][n-1] = true;
            }
        }

        bfs(grid,q,visited,dy,dx);

        int count = 0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }

};