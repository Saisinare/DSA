#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.empty()) return result;

        for (int i = 0; i < strs[0].size(); i++) {
            char currentChar = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != currentChar) {
                    return result;
                }
            }
            result += currentChar; 
        }

        return result;
    }
};


int main() {
    Solution sol;
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};

    cout << "Longest Common Prefix (strs1): " << sol.longestCommonPrefix(strs1) << endl; // Output: "fl"
    cout << "Longest Common Prefix (strs2): " << sol.longestCommonPrefix(strs2) << endl; // Output: ""

    return 0;
}
