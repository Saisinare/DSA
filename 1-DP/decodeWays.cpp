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

/*

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

*/