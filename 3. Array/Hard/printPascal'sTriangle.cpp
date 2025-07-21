//brute force solution for printing pascal's triangle 
class Solution {
public:
    int findNum(int row, int col){
        long long res = 1;
        for(int i =0;i<col;i++){
            res *= (row -i);
            res /= (i+1); 
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i =0;i<numRows;i++){
            vector<int> temp;
            for(int j =0;j<=i;j++){
                temp.push_back(findNum(i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};