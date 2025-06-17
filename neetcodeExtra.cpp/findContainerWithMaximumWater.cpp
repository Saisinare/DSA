class Solution {
public:
    //brute force will be O(N^2) using double i j loop 
    //optimal is this 
    int maxArea(vector<int>& height) {
        int area = 0 ;
        int n = height.size();
        int left = 0 ; 
        int right =  n - 1;
        while(left<right){
                int cArea = min(height[left],height[right])*(right-left);
                area = max(cArea,area);
                if(height[left]<height[right]){
                    left++;
                }else{
                    right--;
                }
        }
        return area;
    }
};