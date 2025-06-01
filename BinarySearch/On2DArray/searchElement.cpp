#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool BettersearchMatrix(vector<vector<int>>& matrix, int target) {
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
    bool OptimalsearchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()*matrix[0].size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int row = mid/matrix[0].size();
            int col = mid%matrix[0].size();
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target){
                high = mid -1;
            }else{
                low = mid +1 ;
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
    cout <<"found by optimal " << sol.OptimalsearchMatrix(matrix, target);
    if (sol.BettersearchMatrix(matrix, target)) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
