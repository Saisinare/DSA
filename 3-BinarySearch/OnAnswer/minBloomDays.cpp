#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = INT_MAX;
        int high = INT_MIN;
        if(bloomDay.size()<m) return -1;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<low){
                low = bloomDay[i];
            }
            if(bloomDay[i]>high){
                high = bloomDay[i];
            }
        }
        int result = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int boquets = findNoOfBoquets(bloomDay, k,mid);

            if(boquets>=m){
                result = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return result;
    }

    int findNoOfBoquets(vector<int>& bloomDay, int k,int mid){
        int count = 0, boquets = 0;
        for(int i =0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
                if(count==k){
                    boquets++;
                    count =0;
                }
            }else{
                count=0;
            }
        }
        return boquets;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum number of days: " << result << endl;

    return 0;
}
