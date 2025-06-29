#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int sum,vector<vector<int>> &result,vector<int> &current,int index){
        if(sum==target){
            result.push_back(current);
            return;
        }
        for(int i =index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(sum>target) break;
                current.push_back(candidates[i]);
                backtrack(candidates,target,sum+candidates[i],result,current,i+1);
                current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,result,current,0);
        return result;
    }
};