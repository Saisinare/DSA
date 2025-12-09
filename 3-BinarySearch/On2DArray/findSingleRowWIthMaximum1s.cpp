#include <iostream>
#include <vector>
using namespace std;
int findLowerBound(vector<int>arr , int m){
    int low = 0 ;
    int high = m-1;
    int answer = -1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(arr[mid]==1){
                answer = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
    return answer;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int max_count = -1;
    int index = -1;

    for(int i =0;i<n;i++){
        int lowerBound = findLowerBound(matrix[i],m); 
        if(lowerBound == -1) continue;
        int count = m - lowerBound;
        if(count>max_count){
            max_count = count;
            index = i;
        }
    }
    return index;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    int result = rowWithMax1s(matrix, n, m);
    cout << "Row with maximum 1s: " << result << endl;

    return 0;
}