#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            int j = i;
            while(j>0 &&  arr[j-1] > arr[j]){
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
            }
        }
    }
};

int main(){
    vector<int> arr = {4,1,3,9,7};
    Solution solution = Solution();
    solution.insertionSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    return 0;
}