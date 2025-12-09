#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int myAtoi(string s) {
        int i = 0 ;
        while(s[i]==' ' && i<s.size()){
            i++;
        }
        int sign = 1;
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign = -1;
            i++;
        }
        long result = 0;
        for(;i<s.size();i++){
            if(!isdigit(s[i])) break;
            result=result*10+(s[i]-'0');
            if(result>INT_MAX ) 
                return (sign==1)?INT_MAX:INT_MIN;
        }
        return result*sign;
    }
};