//Direct optimal solution cause i am cool 
    /*
        1. declare empty stack 
        2. iterate through num 
        3. if stack is not empty and k > 0 and st.top() > num[i] remove the top and decrease the k 
        4. if after the iteration k remainming then remove the k top elements from the stack
        5. now copy every element from stack to new ans string 
        6. reverse the ans as storing from stack to arr reverse the original number 
        7. remove the heading '0'
        8. now if string is empty then return 0 else return string ans as it is 

        Complexity: 
            T.C(O(N))
            S.C.(O(2N))
    */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && (num[i]-'0' < st.top()-'0')) {st.pop(); k--;}
            st.push(num[i]);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i = 0;
        while(i<ans.size() && ans[i]=='0' ) i++;
        ans = ans.substr(i);
        return (ans=="") ? "0":ans; 
    }
};