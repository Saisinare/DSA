class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //brute force: checking every combination possible and then check if it is the maximum 
        int lsum = 0 ;
        int rsum = 0 ;
        for(int i =0;i<k;i++){
            lsum += cardPoints[i];
        }
        int maxPoints = lsum;
        int  lastIndex = cardPoints.size() -1;
        for(int i =k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[lastIndex];
            lastIndex --;
            maxPoints = max(maxPoints,lsum+rsum);
        }
        return maxPoints;
    }
};