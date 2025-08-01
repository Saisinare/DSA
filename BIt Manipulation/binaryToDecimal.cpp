#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int binaryToDecimal(string &b) {
        int len = b.size();
        int ans = 0;
        int ptr = 1;
        for(int i =len-1;i>=0;i--){
            if(b[i]=='1'){
                ans += ptr;   
            }
            ptr *= 2;
        }
        return ans;
    }
};