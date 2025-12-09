#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void merge(vector<int>& arr, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int> temp;
        
        while(left<=mid && right<= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low ;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        int mid = (l+r)/2;
        if(l==r){
            return;
        }
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};
int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    Solution s;
    s.mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}



