#include<bits/stdc++.h>
using namespace std;

//brute force with 0(M*N*backtrack) backtrack:- 4^word.size();
class Solution {
public:
    bool backtrack(int r,int c,int row, int col,vector<vector<char>>& board, string word,int index,set<pair<int,int>> &path){
        if(index>=word.size()) return true;
        if(c<0 || r<0 || r>=row ||c>=col ||word[index]!=board[r][c] ||path.find({r,c})!=path.end()) return false;
        path.insert({r,c});
        bool r1 = backtrack(r+1,c,row,col,board,word,index+1,path);
        bool r2 = backtrack(r-1,c,row,col,board,word,index+1,path);
        bool r3 = backtrack(r,c+1,row,col,board,word,index+1,path);
        bool r4 = backtrack(r,c-1,row,col,board,word,index+1,path);
        path.erase({r,c});

        return r1 || r2 || r3 || r4;

    }
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int,int>> path;
        for(int i = 0 ;i<board.size();i++){
            for(int j =0;j<board[i].size();j++){
                bool res = backtrack(i,j,board.size(),board[i].size(),board,word,0,path);
                if(res) return true;
            }
        }
        return false;
    }
};

//Optmal Solution 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(int r,int c,int row, int col,vector<vector<char>>& board, string word,int index,vector<vector<bool>>& path){
        if(index>=word.size()) return true;
        if(c<0 || r<0 || r>=row ||c>=col ||word[index]!=board[r][c] ||path[r][c]) return false;
        path[r][c] = true;
        bool r1 = backtrack(r+1,c,row,col,board,word,index+1,path);
        bool r2 = backtrack(r-1,c,row,col,board,word,index+1,path);
        bool r3 = backtrack(r,c+1,row,col,board,word,index+1,path);
        bool r4 = backtrack(r,c-1,row,col,board,word,index+1,path);
        path[r][c] = false;

        return r1 || r2 || r3 || r4;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size(); 
        vector<vector<bool>> path(row,vector<bool>(col,false));
        for(int i = 0 ;i<board.size();i++){
            for(int j =0;j<board[i].size();j++){
                bool res = backtrack(i,j,board.size(),board[i].size(),board,word,0,path);
                if(res) return true;
            }
        }
        return false;
    }
};
//0(m*n*4^L) L=size of board 
