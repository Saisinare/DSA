#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();

        while(len>0 && s[len-1] == ' '){
            len--;
        }

        int lastWordLength = 0;
        while(len>0 && s[len-1] != ' '){
            len--;
            lastWordLength ++;
        }
        return lastWordLength;
    }
};


#include <iostream>
using namespace std;

int main() {
    Solution sol;
    string s = "   fly me   to   the moon  ";
    int result = sol.lengthOfLastWord(s);
    cout << result << endl; // Output: 4
    return 0;
}
