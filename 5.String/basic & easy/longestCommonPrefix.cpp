class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if(strs.size()==1) return strs[0];
        if(strs[0].empty()) return "";
        bool isPrefix = true;
        int minSize = strs[0].size();
        for(int i =0;i<strs.size();i++){
            if(strs[i].size()<minSize) {
                minSize = strs[i].size();
            }
        }
        int i =0;
        while(isPrefix && i<minSize){
            char word = strs[0][i];
            int j;
            for(j =0;j<strs.size();j++){
                if(strs[j][i] != word ) {
                        isPrefix = false;
                        break;
                    }
            }
            if( isPrefix == true){
                result += word;
            }
            i++;
        }
        return result;
    }
};

//45 min