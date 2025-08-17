#include<bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    int n = str.size();
    int maxi = 0;
    for(int i = 0;i<n;i++){
    set<int> sett;
        for(int j =i;j<n;j++){
            sett.insert(str[j]);
            if(sett.size()>k){
                break;
            }else{
                maxi = max(j-i+1,maxi);
            }
        }
    }
    return maxi;
}


//brute force with O(N^2 ) T.c.
//O(N) S.C.