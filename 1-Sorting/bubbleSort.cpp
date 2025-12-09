#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        for(int i=arr.size()-1;i>=0;i--){
        int isSwap = 0;
            for(int j=i;j>arr.size()-1-i;j--){
                if(arr[j-1]>arr[j]){
                    isSwap = 1;
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
            if(isSwap == 0){
                break;
            }
        }
    }
};

int main(){
    vector<int> arr = {4,1,3,9,7};
    Solution solution = Solution();
    solution.bubbleSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    return 0;
}