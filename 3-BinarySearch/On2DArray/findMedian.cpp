#include<bits/stdc++.h>
using namespace std;


int findMax(vector<vector<int>> &matrix){
    int maxi = INT_MIN;
    for(int i =0;i<matrix.size();i++){
        if(matrix[i][matrix[0].size()-1]>maxi){
            maxi=matrix[i][matrix[0].size()-1];
        }
    }
    return maxi;
}
int findMin(vector<vector<int>> &matrix){
    int mini = INT_MAX;
    

    for(int i =0;i<matrix.size();i++){
        if(matrix[i][0]<mini){
            mini=matrix[i][0];
        }
    }
    return mini;
}
int findNoOfSmallerElements(vector<vector<int>> &matrix,int target){
    int sum = 0;

    for(int i =0;i<matrix.size();i++){
    int low = 0;
    int high = matrix[i].size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[i][mid]<=target){
                low = mid +1 ;
            }else{
                high = mid -1 ;
            }
        }
        sum += low;
    }
    return sum ;
}
int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = findMin(matrix);
    int high = findMax(matrix);
    while(low<=high){
        int mid = low + (high-low)/2;
        int smallerElements = findNoOfSmallerElements(matrix,mid);
        int required = (n*m+1)/2;
        if(smallerElements<required){
            low = mid +1 ;
        }else{
            high = mid -1;
        }
    }
    return low;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << "Median is: " << getMedian(matrix) << endl;
    return 0;
}
