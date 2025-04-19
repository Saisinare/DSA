#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumKBrute(vector<int> a, long long k) {
    int longest = 0 ;
    for(int i=0;i<a.size();i++){
    int sum = 0 ;
        for(int j=i;j<a.size();j++){
            sum += a[j];
        if(sum == k) longest = max(longest,j-i+1);
        }
    }
    return longest;
}

int longestSubarrayWithSumKBetter(vector<int> a, long long k) {
    int largest  = 0 ;
    map<long long, int> mapp;
    int sum = 0 ;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        if(sum == k){
            largest = max(largest,i+1);
        }
        int rem = sum - k;
        if(mapp.find(rem)!= mapp.end()){
            int len = i - mapp[rem];
            largest = max(largest,len);
        }
        if(mapp.find(sum) == mapp.end()){
            mapp[sum] = i;
        }
    }
    return largest;
}

int longestSubarrayWithSumKOptimal(vector<int> a, long long k) {
    int largest  = 0 ;
    int sum = 0 ;
    int left = 0 ;
    int right = 0;
    while(right<a.size()){

        while(left<a.size() && sum>k){
            sum -= a[left];
            left ++;
        }
        if(sum == k){
            largest = max(largest,right-left+1);
        }
        right++;
        if(right<a.size()) sum += a[right];
    }

    return largest;
}

int main (){

    return -1;
}
