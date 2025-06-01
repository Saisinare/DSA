#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[row].size()-1;
        while(row<matrix.size() && col >=0){
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target){
                col --;
            }else{
                row ++;
            }
        }
        return false;
    }
}; 

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {12, 15, 18, 20},
        {22, 24, 26, 30}
    };

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target found in matrix." << endl;
    } else {
        cout << "Target not found in matrix." << endl;
    }

    return 0;
}