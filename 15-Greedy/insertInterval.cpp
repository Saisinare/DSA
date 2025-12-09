class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0 ;
        //all of the elements which are left side of newInterval 
        while(i<n && newInterval[0] > intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }
        //all of elements which are common / we have to merge 
        while(i<n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        //all of the remaining right sided intervals 
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};