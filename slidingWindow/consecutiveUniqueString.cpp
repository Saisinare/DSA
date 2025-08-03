class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr (256,-1);
        int size = s.size();
        int r = 0, l = 0;
        int maxlen = 0;
        while(r<size){
            if(arr[s[r]]!=-1){
                if(r>=l){
                    l = arr[s[r]]+1;
                }
            }
            maxlen = max(maxlen,r-l+1);
            arr[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};