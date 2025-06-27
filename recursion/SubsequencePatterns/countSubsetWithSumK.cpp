#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int backtrack(vector<int>& arr,int sum,int targetSum,int index){
        if(sum==targetSum) {
            return 1;
        }
        if(index>=arr.size()) return 0;
        if(sum>targetSum) return 0; 
        
        int ans1 = backtrack(arr,sum+arr[index],targetSum,index+1);
        int ans2 = backtrack(arr,sum,targetSum,index+1);
        return ans1 + ans2;
    }
    int isSubsetSum(vector<int>& arr, int sum) {
        
        int result = backtrack(arr,0,sum,0);
        return result;
    }
};
int main(){
    vector<int> arr = {1,2,3,4,5};
    Solution sl = Solution();
    cout<<sl.isSubsetSum(arr,5);
    return 0;
}