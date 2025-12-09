class Solution {
public:
    bool compareStrings(string s1, string s2){
        if(abs((int)s1.size() -  (int)s2.size())!=1) return false;
        if(s1.size() > s2.size() ) swap(s1,s2);
        int i = 0 ;
        int j = 0;
        int diff = 0 ;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }else{
                j++;
                diff ++;
                if(diff>1) return false;
            }
        }
        return true; 
    }
    int longestStrChain(vector<string>& words) {
       int n = words.size();
       vector<int> dp(n,1);
        int maxi = 1;
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size() < b.size();
        });
       for(int i = 1 ; i<n; i++ ){
            for(int j = 0;j<i;j++){
                if(compareStrings(words[j],words[i]) && dp[j] +1 > dp[i] ){
                    dp[i] = dp[j]+1;
                }
            }
            if(dp[i]>maxi) maxi = dp[i];
       } 
       return maxi;
    }
};