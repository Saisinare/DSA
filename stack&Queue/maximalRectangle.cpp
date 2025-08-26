class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] >= currentHeight) {
                int tp = st.top();
                st.pop();
                int height = heights[tp];
                int width = st.empty() ? i : i - st.top() - 1;
                maxi = max(maxi, height * width);
            }
            st.push(i);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, 0));

        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    ans[i][j] = (i == 0 ? 1 : ans[i-1][j] + 1);
                } else {
                    ans[i][j] = 0;
                }
            }
        }

        int maxi = 0;
        for(int i = 0; i < m; i++) {
            maxi = max(maxi, largestRectangleArea(ans[i]));
        }
        return maxi;
    }
};
