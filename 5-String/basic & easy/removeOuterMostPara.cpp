class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0 ;
        string ans = "";
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                if(depth>0) ans += s[i];
                depth ++; 
            }else if(s[i]==')'){
                depth--;
                if(depth>0) ans += s[i];
            }
        }
        return ans;
    }
};