// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 10;
    string ans  = "";
      while(n!=1){
          if(n%2==0){
            ans+='0';
          }else{
             ans+='1';
          }
          n= n/2;
      }
      ans+='1';
      reverse(ans.begin(),ans.end());
      cout<<ans;
      return 0;
}