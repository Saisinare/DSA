//Problem statement: 
/*
    When we segment a string into different subparts, if all those parts are present in the given dictionary (not the string itself) and together they form the entire original string, then return true — otherwise return false.
*/

//Brute force: Starting word search approach 
/*
   1. loop through the dictionary 
   2. consider the dic[i] as starting for search 
   3. for i+1 find the remaining string 
   if entire string is built from the words from dictionary then return true 
   else return false
*/

//Optimal Solution: 1-DP for memoization 
/*
    1. array with track of till ith index are we able to valid segment the string 
    e.g.    s = "catsandog", wordDict = {"cats","dog","sand","and","cat"}
              dp["T","F","F","T","T","F","F","T","F","F"] <- 0th index: even if string is empty we can return true 
              
              Search from ith -> 0 at maxLen in dict 
              Note:  before writing true check if the i - word starting till that point array can be segmented 
              dp["T","F","F","T","T","F","F","T","F","F"]
                      C   a   t   s   a   n   d   o   g
                                  |           |                                    
                                  |___________|
                        if at 4 (start - 1) T then only at 7 (end) the string is segmentable 
                                Note: word is "and" not sand   
            dp["T","F","F","T","T","F","F","T","F","F"]
                    C   a   t   s   a   n   d   o   g
                                            |       |
                                            |_______|
                        at (start -1) F then even if we can make the word the ith will be F as we cannot segment the previouse string 
                        Note: j is already behind one step of start 
                        so no need to check dp[j-1] just check dp[j]     
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
    //convert wordDict to sett for better searching 
    unordered_set<string>sett(wordDict.begin(),wordDict.end()) ;
    int n = s.size();
    vector<bool> dp(n+1,false);
    //empty string can built from the dictionary by not choosing anything from it
    dp[0] = true;
    int maxLen = 0;
    //string.size() always return long 
    for(string st:sett) maxLen = max(maxLen,(int)st.size());

    for(int i = 1;i<=n;i++){
        //range should be either till 0 or i-maxLen
        for(int j = i-1;j>=max(i-maxLen,0);j--){
            if(dp[j] &&
               sett.find(s.substr(j,i-j))!=sett.end()
            ){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
};
