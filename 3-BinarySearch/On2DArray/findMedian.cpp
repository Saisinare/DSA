//Write a function which will calculate the total number of element in matrix which is smaller than equal to the element 
//find upper bound of each row 
//add this upper bound count to the final count 
//if we found that the total smaller or equal elements are == m*n/2 then return it or 

class Solution{
public:
    int findUpperBound(vector<vector<int>>&matrix,int row,int target){
        int low = 0 ;
        int high = matrix[row].size()-1;
        int ans = matrix[row].size();
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[row][mid] > target){
                ans = mid;
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
    int countSmallerOrEqual(vector<vector<int>>&matrix,int target){
        int count = 0 ;
        for(int i=0;i<matrix.size();i++){
            count += findUpperBound(matrix,i,target);
        }
        return count;
    }
    int findMedian(vector<vector<int>>&matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        int req = (m*n)/2;
        int ans = 0;
        for(int i =0;i<m;i++){
            low = min(low,matrix[i][0]);
            high = max(high,matrix[i][n-1]);
        }

        while(low<=high){
            int mid = low + (high-low)/2;
            int smallEqual = countSmallerOrEqual(matrix,mid);
            if(smallEqual > req){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid +1 ;
            }
        }

        return ans;
    }
};



