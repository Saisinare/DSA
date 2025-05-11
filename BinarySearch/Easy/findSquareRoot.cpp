#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 1 ;
        int high = x;
        int ans;
        if(x==0 || x==1) return x;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long sq = 1LL * mid * mid;
            if(sq==x) return mid;
            else if(sq>x) high = mid-1;
            else{
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int x = 9;
    cout<<sol.mySqrt(x);
    return 0;
}