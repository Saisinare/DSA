#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int mini = prices[0] ;
     int profit = 0;
     for(int i =0;i<prices.size();i++){
        int cost = prices[i] - mini;
        profit = max(profit,cost);
        mini = min(mini,prices[i]);
     }   
    return profit;
    }
};
int main(){
    Solution sl = Solution();
    vector<int> arr = {1,2,3,6,7,1,10};
    int maxProfit = sl.maxProfit(arr);
    cout<<maxProfit;
    return 0;
}