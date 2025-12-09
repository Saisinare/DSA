#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int eleIndex = findMax(mat,mid,mat.size());
            int left = (mid-1>=0)?mat[eleIndex][mid-1]:-1;
            int right = (mid+1<mat[eleIndex].size())?mat[eleIndex][mid+1]:-1;
            if(mat[eleIndex][mid]>left && mat[eleIndex][mid]>right) return {eleIndex,mid};
            if(mat[eleIndex][mid]<left){
                high = mid -1;
            }else if(mat[eleIndex][mid]<right){
                low = mid + 1;
            }
        }
        return {};
    }
    int findMax(vector<vector<int>>&arr,int mid,int m){
        int maxi = INT_MIN;
        int rowIndex = -1;
        for(int i = 0;i<m;i++){
            if(arr[i][mid]>maxi){ 
                maxi = arr[i][mid];
                rowIndex = i;
            }
        }
        return rowIndex;
    }
};



int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    vector<int> result = sol.findPeakGrid(mat);
    cout << "Peak found at: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
