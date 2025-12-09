#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0 ;
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a[1] < b[1];
        });
        int lastIndex = intervals[0][1];
        for(int i = 1 ;i<n;i++){
            if(intervals[i][0] < lastIndex)
                count++;
            else 
                lastIndex = intervals[i][1];
        }
        return count;
    }
};