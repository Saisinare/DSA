#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isSafe(vector<string> &board,int n,int col,int row){
        int dummyCol = col;
        int dummyRow = row;

        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        col = dummyCol;
        row = dummyRow;
        while(col>=0 && row<n ){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }

        col = dummyCol;
        row = dummyRow;
        while(col>=0 && row>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row--;
        }
        return true;
    }
    void solve(int n,vector<vector<string>>& result,vector<string> &board,int col,int row){
        if(col==n){
            result.push_back(board);
            return;
        }
        for(int i =0;i<n;i++){
            if(isSafe(board,n,col,i)){
                board[i][col] = 'Q';
                solve(n,result,board,col+1,row);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
        solve(n,result,board,0,0);
        return result;
    }
};