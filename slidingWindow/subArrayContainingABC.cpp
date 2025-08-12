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

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0 ;
        for(int i =0;i<s.size();i++){
            vector<int> mapp(3,0);
            for(int j =i;j<s.size();j++){
                mapp[s[j]-'a'] = 1;
                if(mapp[0]+mapp[1]+mapp[2] == 3){
                    // count ++;
                    //optimization 
                    //as all of the substrings beyond the basic eligible substring which has the "abc" are added to the count 
                    count = count + (s.size()-j);
                    break;
                }
            }
        }
        return count;
    }
};

//O(N^2)
//O(N)
//slightly increase the efficiency but does not clear all of the TLE errors test cases 
