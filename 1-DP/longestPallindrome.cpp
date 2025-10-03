class Solution {
public:
    void expand(string s, int left, int right, int& bestLeft, int& bestRight){
        while(left>= 0 && right <s.size() && s[left] == s[right]){
            left --;
            right ++;
        }
        left++;
        right--;
        if(right - left + 1 > bestRight - bestLeft+1){
            bestLeft = left;
            bestRight = right;
        }
    }
    string longestPalindrome(string s) {
        int bestLeft = 0 ;
        int bestRight = 0;
        for(int i = 0; i<s.size();i++){
            //odd string
            expand(s,i,i+1,bestLeft,bestRight);
            //even string    
            expand(s,i,i,bestLeft,bestRight);       
        }
        return s.substr(bestLeft , bestRight-bestLeft+1);
    }
};