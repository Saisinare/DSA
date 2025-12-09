# Time Complexity: O(n), where n is the size of the input array.
# Space Complexity: O(n), for the stack and result array.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        stack<int> st;
        vector<int> res(arr.size(), -1);
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(arr[i]);
        }
        return res;
    }
};

int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    Solution sol;
    vector<int> result = sol.leftSmaller(arr);

    cout << "Left Smaller Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
