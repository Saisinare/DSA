#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 ;
        int maxi = INT_MIN;
        int start;
        int resultStart,resultEnd;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==0) start = i;

            if(sum>maxi){
                maxi = sum;
                resultStart = start;
                resultEnd = i;
            }
            if(sum<0){
                sum=0;
            }
        }
        cout<<resultStart<<"-"<<resultEnd<<"=";
        return maxi;
    }
};

int main (){
    vector<int> arr = {1,2,3,-1,3,4};
    Solution sl = Solution();
    int maxSum = sl.maxSubArray(arr);
    cout << maxSum;
}