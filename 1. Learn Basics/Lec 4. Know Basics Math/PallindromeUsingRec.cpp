#include<iostream>
#include<string>
using namespace std;

bool isPallindrome(string s,int i,int n){
    if(s[i]!=s[n-i-1]){
        return false;
    }
    if(i>=n-i-1){
        return true;
    }
    return isPallindrome(s,i+1,n);
}

int main(){
    string s = "abcba";
    if(isPallindrome(s,0,5)){
        cout<<s<<" is pallindrome"<<endl;
    }else{
        cout<<s<<" is not pallindrome"<<endl;
    }
    return 0;
}