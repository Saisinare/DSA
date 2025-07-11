#include <bits/stdc++.h> 
void stepForward(vector < vector < int >> & arr, int n,string directions,vector < vector < int >> & vis,vector < string > &result,int x,int y){
    if(x==n-1 && y==n-1){
        result.push_back(directions);
        return;
    }
    //left
    if(x-1>=0 && vis[y][x-1]==0 && arr[y][x-1]==1){
        vis[y][x-1] = 1;
        stepForward(arr,n,directions+'L',vis,result,x-1,y);
        vis[y][x-1] = 0;

    }
    //right
    if(x+1<n && vis[y][x+1]==0 && arr[y][x+1]==1){
        vis[y][x+1] = 1;
        stepForward(arr,n,directions+'R',vis,result,x+1,y);
        vis[y][x+1] = 0;
    }
    //down
    if(y+1<n && vis[y+1][x]==0 && arr[y+1][x]==1){
        vis[y+1][x] = 1;
        stepForward(arr,n,directions+'D',vis,result,x,y+1);
        vis[y+1][x] = 0;
    }
    //up
    if(y-1>=0 && vis[y-1][x]==0 && arr[y-1][x]==1){
        vis[y-1][x] = 1;
        stepForward(arr,n,directions+'U',vis,result,x,y-1);
        vis[y-1][x] = 0;
    }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector < string > result;
    vector < vector < int >> vis(n,vector<int> (n,0));
    if(arr[0][0]==1) {
        vis[0][0] = 1;
        stepForward(arr,n,"",vis,result,0,0);
    }
    sort(result.begin(),result.end());
    return result;
}