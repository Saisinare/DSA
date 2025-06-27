#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>> &result,vector<int>& candidates, int target, vector<int> &current,int index){
        if(index>=candidates.size()){
            if(target==0){
                result.push_back(current);
            }
            return;
        }
        if(candidates[index]<=target){
            current.push_back(candidates[index]);
            backtrack(result,candidates,target-candidates[index],current,index);
            current.pop_back();
        }
        backtrack(result,candidates,target,current,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result,candidates,target,current,0);
        return result;
    }
};