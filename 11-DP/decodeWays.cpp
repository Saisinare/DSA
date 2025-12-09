/*

class Solution {
public:
    int decode(string s, int i ){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;

        int ways = decode(s,i+1);

        if(i+1<s.size()){
            int num = stoi(s.substr(i,2));
            if(num>=10 && num<=26){
                ways += decode(s,i+2);
            }
        }
        return ways;

    }
    int numDecodings(string s) {
        return decode(s,0);
    }
};

decode("226", i=0)
                           |
        ┌──────────────────┴──────────────────┐
        │                                      │
   decode(i=1)                           decode(i=2)
        |                                      |
    ┌───┴───┐                                 |
    │       │                                 |
decode(i=2) decode(i=3)                  decode(i=3)
    │                                         
decode(i=3)

1. Decode i = 1 and i = 3 are redundant part -> Memory Limit Exceed Error 
T.C. (2^n) exponential 
S.C. O(1)

2. use memoization to reduce this TC 
TC: O(N);
SC: O(N);

class Solution {
public:
    vector<int> memo;
    int decode(string s, int i ){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;

        if(memo[i] != -1) return memo[i];

        int ways = decode(s,i+1);

        if(i+1<s.size()){
            int num = stoi(s.substr(i,2));
            if(num>=10 && num<=26){
                ways += decode(s,i+2);
            }
        }
        memo[i] = ways;
        return ways;

    }
    int numDecodings(string s) {
        memo.assign(s.size(),-1);
        return decode(s,0);
    }
};

*/
#include<iostream>
#include<string>
using namespace std;
//TC: O(N)
//SC: O(1)
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int prev1 = 1 , prev2 = 1;
        for(int i =1 ;i<s.size();i++){
            int current = 0 ;
            if(s[i]!='0'){
                current = prev1;
            }

            int num = stoi(s.substr(i-1,2));
            if(num>=10 && num<=26){
                current+=prev2;
            }
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
