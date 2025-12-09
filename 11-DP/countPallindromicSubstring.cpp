class Solution {
public:
    void expand(string s, int left, int right,int & count){
        while(left>= 0 && right <s.size() && s[left] == s[right]){
            left --;
            right ++;
            count++;
        }
        left++;
        right--;

    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i<s.size();i++){
            //odd string
            expand(s,i,i+1,count);
            //even string    
            expand(s,i,i,count);       
        }
        return count;
    }
};
// Time Complexity: O(n^2), where n is the length of the string.
// Space Complexity: O(1).
