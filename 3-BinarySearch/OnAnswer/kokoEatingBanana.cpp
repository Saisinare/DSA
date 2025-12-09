#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        if(piles.size() == 1){
            return ceil(piles[0]/(double)h);
        }
        //find the maximum for rang of answer;
        for(int i =0;i<piles.size();i++){
            if(piles[i]>maxi){
                maxi = piles[i];
            }
        }

        //find the no of bananas he should eat
        int low =1;
        int high = maxi;
        int result = INT_MAX;

        while(low<=high){
            long long sumHours = 0;
            int mid = low + (high-low)/2;
            //find how many hours required to eat all 
            for(int i = 0;i<piles.size();i++){
                sumHours += ceil(piles[i]/(double)mid);
            }
            if(sumHours<=h){
                result =mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        }
        return result;
    }
};
int main() {
    Solution sol;

    // Sample test case: piles = [3, 6, 7, 11], h = 8
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}