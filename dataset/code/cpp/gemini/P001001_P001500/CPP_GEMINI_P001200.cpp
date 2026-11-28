#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix[0].size();
        std::vector<int> heights(n + 1, 0);
        int maxArea = 0;

        for (const auto& row : matrix) {
            for (int i = 0; i < n; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            std::stack<int> stack;
            stack.push(-1);
            for (int i = 0; i <= n; i++) {
                while (stack.top() != -1 && heights[stack.top()] >= heights[i]) {
                    int h = heights[stack.top()];
                    stack.pop();
                    int w = i - stack.top() - 1;
                    maxArea = std::max(maxArea, h * w);
                }
                stack.push(i);
            }
        }
        return maxArea;
    }
};