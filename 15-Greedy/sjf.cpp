class Solution {
  public:
    long long solve(vector<int>& bt) {
        //Sort the bt array 
        int n = bt.size();
        sort(bt.begin(),bt.end());
        //Start iterating from 0->n 
        long long wt = 0 ;
        long long totalTime = 0 ;
        for(int i =0;i<n;i++){
          totalTime += wt;
          wt += bt[i]; 
        }
        return totalTime/n;
    }
};