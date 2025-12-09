#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>> &result,int n, int k, vector<int> &current,int index){
        if(index>n){
            if(current.size()==k){
                result.push_back(current);
            }
            return;
        }
        current.push_back(index);
        backtrack(result,n,k,current,index+1);

        current.pop_back();

        backtrack(result,n,k,current,index+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result,n,k,current,1);
        return result;
    }
};

/*
TC : C(N,K)*K;
SC : C(N,K)*k+N;
*/