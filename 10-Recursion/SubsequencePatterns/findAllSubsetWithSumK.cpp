#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void backtrack(vector<int>& arr,vector<int> &current,vector<vector<int>>& result,int sum,int targetSum,int index){
        if(sum==targetSum) {
            result.push_back(current);
            return;
        }
        if(index>=arr.size() || sum>targetSum ) return ;

        current.push_back(arr[index]);
        backtrack(arr,current,result,sum+arr[index],targetSum,index+1);
        current.pop_back();
        backtrack(arr,current,result,sum,targetSum,index+1);
    }
    vector<vector<int>> isSubsetSum(vector<int>& arr, int sum) {
        
        vector<vector<int>> result;
        vector<int> current;
        backtrack(arr,current,result,0,sum,0);
        return result;
    }
};
int main(){
    Solution sl = Solution();
    vector<int> nums = {1,2,3,4,5};
    int k = 6;
    vector<vector<int>> result = sl.isSubsetSum(nums,k);
    for(vector<int> res: result){
        for(int i:res){
            cout<<i<<",";
        }
        cout<<endl;
    }
    return 0;
}

