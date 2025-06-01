#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> result;
        int max_count = -1;
        for(int i =0;i<mat.size();i++){
            int count = 0;
            for(int j =0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            if(count>max_count){
                result.clear();
                result.push_back(i);
                result.push_back(count);
                max_count = count;
            }else if(count==max_count){
                result[1] = max_count;
            }
        }
    return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 1, 1},
        {1, 1, 1},
        {0, 0, 1}
    };

    vector<int> result = sol.rowAndMaximumOnes(mat);
    cout << "Row with maximum ones: " << result[0] << ", Count: " << result[1] << endl;

    return 0;
}
