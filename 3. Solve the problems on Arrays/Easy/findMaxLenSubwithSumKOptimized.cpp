#include <iostream>
#include<vector>
#include<map>
//for positive numbers only
using namespace std;

int findLargestSubArrayWithSumK(vector<int> arr,int k){
    long long sum = 0;
    int maxLen =0;
    int left =0;int right =0;
    while( right<arr.size()){

        if(right<arr.size()){
            sum +=arr[right];
        }

        while(left<=right && sum>k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(right-left+1,maxLen);
        }
        right++;

    }
    return maxLen;
}

int main(){
    vector<int> arr ={2,3,1,1,1};
    int maxLenOfLargestKSumArray = findLargestSubArrayWithSumK(arr,3);
    cout<<maxLenOfLargestKSumArray;
    return 0;
}