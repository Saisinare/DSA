#include <bits/stdc++.h>
using namespace std;
//brute force approach
//getting TLE on large test cases 
class Solution {
public:
    void traverse(vector<vector<int>>& mat,int m,int n,pair<int,int> node){
        queue<pair<int,int>> q;
        q.push(node);
        int dist = 0;
        int nodeI = node.first;
        int nodeII = node.second;
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 
        visited[nodeI][nodeII] = true;

        while(!q.empty()){
            int size = q.size();
            dist++;
        
            for(int k =0;k<size;k++){
                pair<int,int> front = q.front();
                int i = front.first; 
                int j = front.second;

                q.pop();
                //left 
                if(j>0 && !visited[i][j-1]){
                    if (mat[i][j-1] == 0){
                        mat[nodeI][nodeII] = dist;
                        return;
                    }
                    q.push({i,j-1});
                    visited[i][j-1] = true;
                }
                //right 
                if(j<n-1 && !visited[i][j+1]){
                    if (mat[i][j+1] == 0){
                        mat[nodeI][nodeII] = dist;
                        return;

                    }
                    q.push({i,j+1});
                    visited[i][j+1] = true;
                }
                //up 
                if(i>0 && !visited[i-1][j]){
                    if (mat[i-1][j] == 0 ){
                        mat[nodeI][nodeII] = dist;
                        return;
                    }
                    q.push({i-1,j});
                    visited[i-1][j] = true;
                }
                //down 
                if(i<m-1 && !visited[i+1][j]){
                    if (mat[i+1][j] == 0){
                        mat[nodeI][nodeII] = dist;
                        return;
                    }
                    q.push({i+1,j});
                    visited[i+1][j] = true;
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty()) return {};
        int m = mat.size();
        int n = mat[0].size();
        //check where is 1 from that point start BFS traversing
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j] == 1){
                    traverse(mat,m,n,{i,j});
                }
            }
        }

        return mat;
    }
};

//TC: O((m*n)^2) SC: O(m*n) for visited array and queue

//optimal approach
class Solution {
public:
    void bfs(vector<vector<int>>& mat,queue<pair<int,int>>& q,int m,int n){
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;

            for(int k =0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<m && nj>=0 && nj<n && mat[ni][nj]==-1){
                    mat[ni][nj] = mat[i][j]+1;
                    q.push({ni,nj});
                }
            }

        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j] = -1;
            }
        }
        bfs(mat,q,m,n);
        return mat;
    }
};

//TC :  O( 2x(mxn) ) == O(mxn) as we are traversing every node 
//SC :  O(mxn) as in the worst case if their is only single one our queue will have all nodes-1 which is something mxn