#include<bits/stdc++.h>
using namespace std;

//brute force approach 
    /*
        1. create a function which will calculate the maximum in the given length 
        2. find the left maximum and the right maximum for every element 
        3. substract the minimum hight from the  i 
        4. if sum is in positive add it to the final answer 
        5. return sum 
    */
class Solution {
public:
    int findMax(int start, int end,vector<int>& height ){
        int maxi = 0;
        for(int i =start;i<=end;i++){
            maxi = max(maxi,height[i]); 
        }
        return maxi;
    }
    int trap(vector<int>& height) {
        int ans = 0; 
        for(int i =0;i<height.size();i++){
            int h1 = findMax(0,i-1,height);
            int h2 = findMax(i+1,height.size()-1,height);
            int val = min(h1,h2) - height[i]; // mosin's way 
            // if(h1 > height[i] && h2>height[i]){
            //     ans += min(h1,h2)-height[i];
            // } striver's way 
            if(val>0){
                ans += val;
            }
        }
        return ans;
    }
};


/*
O(N^2);
O(1)
 */



//better 
    /*
    Using Prefix and sufix array 
    1. create a prefix array and store the highest element of the arr relative index from the left max(i-1,i)
    2. create a sufix array store the highest element form the left for each element 
    3. subtract the arr[i] from min of   sufix[i] and prefix[i] 
    4. add this val to the ans ;
    5. return ans 

    */
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0 ;
        int n = height.size();
        vector<int> prefix(n,0);
        vector<int> sufix(n,0);
        prefix[0] = height[0];
        for(int i =1;i<n;i++){
            prefix[i] = max(prefix[i-1],height[i]);
        }
        sufix[n-1] = height[n-1];
        for(int i =n-2;i>=0;i--){
            sufix[i] = max(sufix[i+1],height[i]);
        }
        for(int i =0;i<n;i++){
            ans += (min(prefix[i],sufix[i]) - height[i]);
        }
        return ans;
    }
};

//O(N) S.C
//O(N) T.C



