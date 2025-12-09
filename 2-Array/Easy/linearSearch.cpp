#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int linearSearch(vector<int> arr,int k){
        for(int i=0;i<arr.size();i++){
            if(arr[i] == k){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    vector<int> arr = {1,2,3,4,0,0,5,2};
    Solution sl = Solution();
    int index = sl.linearSearch(arr,3);
    if(index != -1){
        cout<<index;
    }else{
        cout<<"element not found";
    }
}