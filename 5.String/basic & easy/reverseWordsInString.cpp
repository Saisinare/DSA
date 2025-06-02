#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
string BruteReverseWords(string s) {
        string word = "";
        vector<string> words = {};

        //splitting the array 
        for(int i =0;i<s.size();i++){
            if(s[i]!=' ' ) word = word + s[i];
            else if((word!="")){
                words.push_back(word);
                word = "";
            }
        }
        if(!word.empty()) words.push_back(word);

        //reversing the array 
        reverse(words.begin(),words.end());

        //joining the array 
        string result = "";
        for(int i =0;i<words.size();i++){
            result += words[i];
            if(i!=words.size()-1)
                result += " ";
        }
        return result;
    }
    string OptimalReverseWords(string s) {
        int left = 0 ; 
        int right = s.size()-1;
        while(s[left]==' ' || s[right]==' '){
            if(s[left]==' ') left ++;
            if(s[right]==' ') right --;
        }
        string temp = "";
        string ans = "";
        while(right>=left){
            if(s[right]!=' '){
                temp+= s[right];
            }else if(!temp.empty()){
                reverse(temp.begin(),temp.end());
                ans+= temp + " ";
                temp.clear();
            }
            right--;
        }
        if(!temp.empty()){
            reverse(temp.begin(),temp.end());
            ans+= temp;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "  Hello   World!  ";

    cout << "Brute Force Result: \"" << sol.BruteReverseWords(input) << "\"" << endl;
    cout << "Optimal Result: \"" << sol.OptimalReverseWords(input) << "\"" << endl;

    return 0;
}
