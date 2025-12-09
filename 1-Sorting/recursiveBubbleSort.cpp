#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:

    void bSort(vector<int>& arr,int n){
        if(n==1) return;
        int didSwap = 0;
        for(int i=0;i<=n-2;i++){
            if(arr[i]>arr[i+1]){
                didSwap = 1;
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        if(didSwap==0){
            return;
        }
        bSort(arr,n-1);
    }
    void bubbleSort(vector<int>& arr) {
            int n = arr.size();
            bSort(arr,n);
    }
};

int main(){
    vector<int> arr = {10,3,34,1,2,4,20};
    Solution solution = Solution();
    solution.bubbleSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    return 0;
}