class Solution{  
  public:  
    static bool compare(vector<int>& a,vector<int>& b){
      return a[2] > b[2];
    }
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
      int n = Jobs.size();
      sort(Jobs.begin(),Jobs.end(),compare);
      int maxDeadline = -1;
      
      for(auto& job :Jobs){
        maxDeadline = max(maxDeadline,job[1]);
      }

      vector<int> jobSchedule(maxDeadline,-1);

      int count = 0 ;
      int profit = 0 ;
      
      for(int i =0;i<n;i++){
        for(int j = Jobs[i][1]-1;j>=0;j--){
          if(jobSchedule[j]==-1){
            count++;
            profit+=Jobs[i][2];
            jobSchedule[j] = Jobs[i][0];
            break;
          }
        }
      }
    return {count,profit};
    } 
};