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

#include<bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    int r = 0 , l =0;
    map<char,int> mapp;
    int maxi = 0;
    while(r<str.size()){
        mapp[str[r]]++;
        while(mapp.size()>k && l<str.size()){
            mapp[str[l]]--;
            if(mapp[str[l]]==0) mapp.erase(str[l]);
            l++;
        }
        maxi = max(maxi,r-l+1);
        r++;
    }
    return maxi;
}


//optimal solution 
/*
1. create a map structure to count the frequency of elements in the window 
2. if the map.size() > k trim the window 
3. (edge case) whenever the frequency of an element reach the 0 do not forget to erase it from hash map 
4.  compare the maxi with r-l+1 and replace maxi with it 
*/