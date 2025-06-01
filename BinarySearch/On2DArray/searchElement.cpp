#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i =0;i<matrix.size();i++){
            int low = 0;
            int high = matrix[i].size()-1;
            if(matrix[i][low]<=target && matrix[i][high]>=target){
                while(low<=high){
                    int mid = low + (high-low)/2;
                    if(matrix[i][mid] == target) return true;
                    if(matrix[i][mid]>target){
                        high = mid -1;
                    }else{
                        low = mid+1;
                    }
                }
            }
        }
        return false;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target = 3;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
