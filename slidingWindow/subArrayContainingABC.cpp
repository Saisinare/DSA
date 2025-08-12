class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0 ;
        for(int i =0;i<s.size();i++){
            vector<int> mapp(3,0);
            for(int j =i;j<s.size();j++){
                mapp[s[j]-'a'] = 1;
                if(mapp[0]+mapp[1]+mapp[2] == 3){
                    count ++;
                }
            }
        }
        return count;
    }
};

//O(N^2)
//O(1)