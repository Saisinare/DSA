

class Solution{
public:
    int dfs(vector<vector<int>> &grid,int m ,int n,queue<pair<int,int>>& q,int& fresh){
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        int count = 0 ;
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int k =0;k<4;k++){
                    int nr = row + dx[k];
                    int nc = col + dy[k];
                    if(nr>=0 && nr<m && nc>=0 && nc <n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    } 
                }
            }
            if(!q.empty()) count++;
        }
    return count;
    }
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        //O(M*N)
        int fresh = 0;
        bool hasRotten = false ;

        //O(m*n)

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    hasRotten = true;
                    q.push({i,j});
                }
            }
        }
        // if their is no fresh oranges then time is 0 
        if(fresh==0) return 0;
        // if their is no rotten oranges then it is not possible to to rotten entire grid so return -1 
        if(!hasRotten) return -1;

        // do dfs and if after that if their is even a single fresh orange then return -1 
        //O(m*n)

        int count = dfs(grid,m,n,q,fresh);
        // fresh = 0 ;
        //O(M*N)
        // for(int i =0;i<m;i++){
        //     for(int j =0;j<n;j++){
        //         if(grid[i][j] == 1){
        //             fresh++;
        //         }
        //     }
        // }
        //instead of this just pass the fresh count to dfs and decrease it when you rotten something 
        if(fresh != 0) return -1;
        return count;

    }
};

//Time complexity:  O(M*N)
//Space complexity: O(M*N)



