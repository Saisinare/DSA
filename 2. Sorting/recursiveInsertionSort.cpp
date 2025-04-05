#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void Isort(vector<int>& arr, int i,int n){
        if(i==n){
            return;
        }
        int j = i ;
        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
        Isort(arr,++i,n);
    }
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        Isort(arr,0,n);
    }
};


int main(){
    vector<int> arr = {10,3,34,1,2,4,20};
    Solution solution = Solution();
    solution.insertionSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    return 0;
}