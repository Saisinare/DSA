class Solution {
public:
    int splitArrayAndReturnSplitCount(vector<int> &a,int k){
        int count = 1;
        int sum = 0;
        for(int i =0;i<a.size();i++){
            if(sum+a[i]<=k){
                sum+=a[i];
            }else{
                sum = a[i];
                count ++;
            }
        }
        return count;
    }
    int largestSubarraySumMinimized(vector<int> &a, int k) {
        int low = *max_element(a.begin(),a.end());
        int high = accumulate(a.begin(),a.end(),0);
        if(k>a.size()) return -1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int count = splitArrayAndReturnSplitCount(a,mid);
            if(count <= k){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

// if mid increases : number of subarrays (count) decreases
// if mid decreases : number of subarrays (count) increases
