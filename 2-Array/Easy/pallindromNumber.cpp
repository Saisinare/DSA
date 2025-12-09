#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isPalindrome(int x) {
        long rev = 0 ;
        int temp =x ;
        while(temp>0){
            rev *=10;
            rev += temp % 10;
            temp /= 10;
        }
        if(rev == x){
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (sol.isPalindrome(num)) {
        cout << num << " is a palindrome." << std::endl;
    } else {
        cout << num << " is not a palindrome." << std::endl;
    }

    return 0;
}