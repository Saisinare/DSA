#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
            int partitionIndex = partition(arr,low,high);
            quickSort(arr,low,partitionIndex-1);
            quickSort(arr,partitionIndex+1,high);
        }

    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        
        while(i<j){
            while(arr[i] <= pivot && i<high){
                i++;
            }
            while(arr[j]>=pivot && j>low){
                j--;
            }
            if(i<j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j]= temp;
            }
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        return j;
    }
};

int main(){
    vector<int> arr = {10,3,34,1,2,4,20};
    Solution solution = Solution();
    solution.quickSort(arr,0,6);
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    return 0;
}