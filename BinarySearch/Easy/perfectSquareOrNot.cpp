#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1; 
        int high = num;

        while(low<=high){
            long long mid = low+ (high-low)/2;
            long long sqr = mid*mid;
            if(sqr == num){ 
                return true;
            }
            else if(sqr>num) {
                 high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};
int main() {
    Solution solution;
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (solution.isPerfectSquare(number)) {
        cout << number << " is a perfect square." << endl;
    } else {
        cout << number << " is not a perfect square." << endl;
    }

    return 0;
}
