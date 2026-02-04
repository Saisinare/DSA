//find the peak row with max element column wise 
//see if the right and left of that element is smaller if yes then return this row and mid 
//if left half is greater than the element then answer is in the left half 
//or answer is in the right half 
class Solution {
public:
    int findMaxElementIndex(vector<vector<int>>& mat,int col){
        int m = mat.size();
        int maxi = INT_MIN;
        int idx = -1;
        for(int i = 0;i<m;i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col]; 
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0 ;
        int high = m -1;
        while(low <= high){
            int mid = low + (high - low )/2;
            int row = findMaxElementIndex(mat,mid);

            int left = mid-1>=0? mat[row][mid-1] : INT_MIN;
            int right = mid +1 <m ? mat[row][mid+1]: INT_MIN;

            if(mat[row][mid]>left && mat[row][mid]>right ) return {row,mid};
            else if(mat[row][mid]<left) high = mid -1;
            else low = mid +1;
        }
        return {};
    }
};

//Time Complexity: O(N Log M)
//Space Complexity: O(1)