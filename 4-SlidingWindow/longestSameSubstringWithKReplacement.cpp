//brute force solution O(N^2)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        for(int i =0;i<s.size();i++){
            int maxF = 0; 
            vector<int> hash(26,0);
            //keep the hash table for each element from a to z
            for(int j =i;j<s.size();j++){
                //increase the count in the hash according to the letter 
                hash[s[j]-'A'] ++;
                //check who has the most frequency and updat it 
                maxF = max(maxF,hash[s[j]-'A']);
                //calculate how many characters i have to change so we can get the longest substring with same characters 
                int changes = (j-i+1) - maxF;
                //if changes are smaller or equal to the k then update the maxLen
                if(changes<=k){
                    maxLen = max(maxLen,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxLen;
    }
};

//optimal solution O(N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int left = 0 , right =0;
        int maxFreq = 0;
        vector<int> hash(26,0);
        while(right<s.size()){
            hash[s[right]-'A']++;
            maxFreq = max(maxFreq,hash[s[right]-'A']);
            while((right-left+1)-maxFreq>k){
                hash[s[left]-'A']--;
                left++;
            }
                maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};