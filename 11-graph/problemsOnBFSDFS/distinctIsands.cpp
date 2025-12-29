#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dy = {-1,1,0,0};
    vector<int> dx = {0,0,-1,1};
    void traverse(vector<vector<char>>& grid,int m,int n,int i,int j){
        grid[i][j] = '0';
        for(int k = 0;k<4;k++){
            int ni = i + dy[k];
            int nj = j + dx[k];
            if(ni>=0 && ni<m && nj>=0 && nj < n && grid[ni][nj] == '1'){
                traverse(grid,m,n,ni,nj);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0 ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    traverse(grid,m,n,i,j);
                    count++;
                }
            }
        }

        return count;
    }
};

//TC: O(m*n) 
//SC: O(m*n)
