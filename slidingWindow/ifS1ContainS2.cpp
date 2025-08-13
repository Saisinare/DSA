class Solution {
public:
    bool isSame(vector<int> freq1,vector<int> freq){
        for(int i =0;i<freq1.size();i++){
            if(freq1[i]!=freq[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        //keep the counters for the frequency for each character in the first string 
        for(int i =0;i<s1.size();i++){
            freq[s1[i]-'a'] ++;
        }
        //count the freqeuncy of each character in the every possible window 
        int widSize = s1.size();
        for(int i =0;i<s2.size();i++){
            int winIndex = 0; 
            int index = i ; 
            vector<int> Winfreq(26,0);
            while(winIndex<widSize && index<s2.size()){
                Winfreq[s2[index]-'a']++;
                winIndex++;
                index++;
            }
            if(isSame(freq,Winfreq)==true) return true;
        }
        return false;
    }
};