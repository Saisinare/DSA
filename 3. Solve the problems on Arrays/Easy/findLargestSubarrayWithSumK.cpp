#include <iostream>
#include<vector>
#include<map>
//for positive numbers only
using namespace std;

int findLargestSubArrayWithSumK(vector<int> arr,int k){
    long long sum = 0;
    int maxLen =0;
    map<long long,int> hashmap;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum==k){
           maxLen = max(maxLen,i+1);
        }
        int rem = sum-k;
        if(hashmap.find(rem)!= hashmap.end() ){
            int len = i-hashmap[rem];
            maxLen = max(len,maxLen);
        }
        if(hashmap.find(sum) == hashmap.end()){
        hashmap[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr ={2,1,3,1,1};
    int maxLenOfLargestKSumArray = findLargestSubArrayWithSumK(arr,3);
    cout<<maxLenOfLargestKSumArray;
    return 0;
}