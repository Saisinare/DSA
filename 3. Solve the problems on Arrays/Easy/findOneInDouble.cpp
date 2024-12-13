//find the number which appears only once in the array where every element in the array is appears twice 
#include <bits/stdc++.h>
using namespace std;
//TC O(n)
    int findOneElement(vector<int>& nums) {
        int xor1 = 0;
        for(int i=0;i<nums.size();i++){
            xor1 = xor1^nums[i];
        }
        return xor1;
    }
int main(){

    vector<int> arr = {1,1,2,2,3,3,4,5,5};
    int onlyOnceAppearingNum = findOneElement(arr);
    cout<<"Number which appears only one: "<<onlyOnceAppearingNum;
    return 0;
}