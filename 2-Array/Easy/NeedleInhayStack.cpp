#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = -1;
        int Hlength = haystack.size();
        int NLen = needle.size();

        for(int i = 0 ;i<=Hlength-NLen;i++){
            int j = 0 ;
            for(;j<NLen;j++){
                if(needle[j]!=haystack[j+i]){
                    break;
                }
            }
            if (j==NLen){
                result = i;
                break;
            }
        }
        return result;
    }
};



int main() {
    Solution solution;
    string haystack = "hello";
    string needle = "ll";
    int index = solution.strStr(haystack, needle);
    cout << "Index: " << index << endl;
    return 0;
}