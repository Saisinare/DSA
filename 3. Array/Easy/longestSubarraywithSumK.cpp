#include<bits/stdc++.h>
using namespace std;

//brute force 
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int maxi = 0;
        for(int i =0;i<arr.size();i++){
            int sum = 0 ;
            for(int j = i;j<arr.size();j++){
                sum += arr[j];
                if(sum==k){
                    maxi = max(j-i+1,maxi);
                }
            }
        }
        return maxi;
    }
};
//better 
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<long long,int> mapp;
        long long sum = 0 ;
        int maxi = 0;
        mapp[0] = -1;
        for(int i =0;i<arr.size();i++){
            sum+=arr[i];
            if(sum == k ){
                maxi = i+1;
            }
            long long res = sum -k;
            if(mapp.find(res)!=mapp.end()){
                maxi = max(maxi,i-mapp[res]);
            }
            if(mapp.find(sum)==mapp.end()){
                mapp[sum] = i;
            }
        }
        return maxi;
    }
};
//optimal 
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        long long sum = 0 ;
        int i = 0 ,j = 0;
        int maxi = 0;
        while(j<arr.size()){
            
            sum += arr[j];
            
            while(i<arr.size() && sum>k){
                sum -= arr[i];
                i++;
            }
            
            if(sum==k){
                maxi = max(j-i+1,maxi);
            }
            
            j++;

        }
        return maxi;
    }
};