class Solution {
  public:
    bool backtrack(vector<int>& arr,int sum,int targetSum,int index){
        if(sum==targetSum) return true;
        if(index>=arr.size()) return false;
        if(sum>targetSum) return false; // only works if the array contain the non negative numbers 
        
        bool ans1 = backtrack(arr,sum+arr[index],targetSum,index+1);
        bool ans2 = backtrack(arr,sum,targetSum,index+1);
        return ans1 || ans2;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        bool result = backtrack(arr,0,sum,0);
        return result;
    }
};