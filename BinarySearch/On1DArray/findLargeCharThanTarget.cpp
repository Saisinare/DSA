#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char result = letters[0];
        int low = 0;
        int high = letters.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(letters[mid] > target){
                result = letters[mid];
                high  = mid-1;
            }else{
                low = mid +1;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'd';
    char result = sol.nextGreatestLetter(letters, target);
    cout << "Next greatest letter: " << result << endl;
    return 0;
}