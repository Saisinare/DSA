class Solution {
  public:   
  int findNoOfOnes(vector<int> row){
    int low = 0;
    int high = row.size()-1;
    int firsOnetIdx = row.size() ;
    while(low <= high){
      int mid = low + (high - low )/2;
      if(row[mid] == 1){
        firsOnetIdx = mid;
        high = mid - 1;
      }else{
        low = mid + 1;
      }
    }
    return row.size() - firsOnetIdx;
  }
  int rowWithMax1s(vector < vector < int >> & mat) {
    //Find the first occurence of one in every row compare subtract from its length compare and undate maxi 
    int maxOnes = 0;
    int row = -1;
    for(int i =0;i<mat.size();i++){
      int noOfOnes = findNoOfOnes(mat[i]);
      // cout<<""<<i<<":"<<noOfOnes<<endl;
      if(noOfOnes>maxOnes){
        maxOnes = noOfOnes;
        row = i;
      }
    }
    return row;
  }
};