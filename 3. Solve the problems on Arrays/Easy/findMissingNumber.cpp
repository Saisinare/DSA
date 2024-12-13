#include <bits/stdc++.h>
using namespace std;
//TC O(n)
    int findMissingNumber(vector<int>& nums) {
    
        int xor1=0;
        int xor2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xor1 = xor1^(i);
            xor2 = xor2^nums[i];
        }
        xor2=xor2^(n);
        
        return xor1^xor2;
    }
int main(){

    vector<int> arr = {0,1,2,6,4,5};
    int missing = findMissingNumber(arr);
    cout<<"missing number is: "<<missing;
    return 0;
}