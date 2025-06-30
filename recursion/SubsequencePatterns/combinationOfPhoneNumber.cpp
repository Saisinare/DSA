class Solution {
public:
    void backtrack(string &digits, vector<string> &result, string current, int index, unordered_map<char, string> &mapp) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        char digit = digits[index];
        for (char c : mapp[digit]) {
            backtrack(digits, result, current + c, index + 1, mapp);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mapp = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
        };

        vector<string> result;
        backtrack(digits, result, "", 0, mapp);
        return result;
    }
};
