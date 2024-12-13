#include<iostream>
#include<string>
using namespace std;

int main(){
    //26 size for lower case letters only 
    //for upper and lower case the size of letters will be 0 to 256
    string s ;
    cin>>s;

    //precompute 
    int hash[26] = {0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }

    int q;
    cin>>q;
    while(q--){
        char ch;
        cin >>ch;
        cout<<hash[ch-'a']<<endl;
    }
    return 0;
}