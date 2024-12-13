#include<iostream>
using namespace std;

int findPallindrome(int n) {
    int reverse = 0;
    int num = n;
    while (n > 0) {
        int temp = n % 10;
        reverse = reverse * 10 + temp;
        n /= 10;
    }
    if(reverse == num){
        return true;
    }else{
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    bool isPallindrome = findPallindrome(n);
    if (isPallindrome == true) {
        cout << n << " is a palindrome";
    } else {
        cout << n << " is not a palindrome";
    }
    return 0;
}
