class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        map<char,int> mapp;
        for (char c : t) mapp[c]++;  

        int need = mapp.size();
        int have = 0;
        map<char,int> window;

        int minLen = INT_MAX;
        int bestLeft = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (mapp.count(c) && window[c] == mapp[c]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    bestLeft = l;
                }

                char leftChar = s[l];
                window[leftChar]--;
                if (mapp.count(leftChar) && window[leftChar] < mapp[leftChar]) {
                    have--;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(bestLeft, minLen);
    }
};
