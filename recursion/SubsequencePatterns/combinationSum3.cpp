#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int k, int n,vector<vector<int>> &result,vector<int> current,int sum,int index){
        if(current.size()==k){
            if(sum==n) result.push_back(current);
            return;
        }
        for(int i =index;i<=9;i++){
            if(i>n) break;
            current.push_back(i);
            backtrack(k,n,result,current,sum+i,i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(k, n,result,current,0,1 );
        return result;
    }
    
};