//Using only BFS will be optimal approach 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int,int>> q;
        vector<vector<int>> distance(n,vector<int>(n,1e9));
        q.push({0,0});
        distance[0][0] = 1;

        vector<int> dx = { 1,  1,  1,  0,  0, -1, -1, -1 };
        vector<int> dy = { 1,  0, -1,  1, -1,  1,  0, -1 };

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            int currDist = distance[i][j];
            q.pop();
            for(int k =0;k<8;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] == 0 && currDist+1 < distance[ni][nj]){
                    q.push({ni,nj});
                    distance[ni][nj] = currDist + 1;
                }
            }
        }
        return (distance[n-1][n-1] == 1e9) ? -1 :distance[n-1][n-1];
    }
};

//most optimal use grid itself to store distance instead of using extra space
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1; //storing distance in grid itself

        vector<int> dx = { 1,  1,  1,  0,  0, -1, -1, -1 };
        vector<int> dy = { 1,  0, -1,  1, -1,  1,  0, -1 };

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            int currDist = grid[i][j];
            q.pop();
            for(int k =0;k<8;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] == 0){
                    q.push({ni,nj});
                    grid[ni][nj] = currDist + 1; //storing distance in grid itself
                }
            }
        }
        return (grid[n-1][n-1] == 0) ? -1 :grid[n-1][n-1];
    }
};

//time complexity: O(n*n)   
//space complexity: O(n*n) for queue in worst case
