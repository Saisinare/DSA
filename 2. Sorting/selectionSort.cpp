#include<iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        for(int i=0;i<=arr.size()-2;i++){
            int min = i;
            for(int j=i;j<=arr.size()-1;j++){
                if(arr[j]<arr[min]){
                    min= j;
                }
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
};

int main(){
    vector<int> arr = {10,3,34,1,2,4,20};
    Solution solution = Solution();
    solution.selectionSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    return 0;
}