#include <vector>
#include <stack>
#include <algorithm>

class Solution {
    int largestHist(std::vector<int>& heights) {
        std::stack<int> st;
        int maxArea = 0, n = heights.size();

        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            // Maintain monotonic stack property by popping smaller elements
            while (!st.empty() && heights[st.top()] > h) {
                int top = st.top();
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = std::max(maxArea, heights[top] * w);
            }
            st.push(i);
        }
        return maxArea;
    }
public:
    int maxArea(std::vector<std::vector<int>>& M, int n, int m) {
        std::vector<int> heights(m, 0);
        int maxRect = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = (M[i][j] == 1 ? heights[j] + 1 : 0);
            }
            maxRect = std::max(maxRect, largestHist(heights));
        }
        return maxRect;
    }
};