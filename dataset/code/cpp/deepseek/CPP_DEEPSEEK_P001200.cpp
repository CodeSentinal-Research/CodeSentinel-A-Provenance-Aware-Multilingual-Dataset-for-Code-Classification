#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;

    int maxArea = 0;
    vector<int> heights(matrix[0].size() + 2, 0);
    for (int i = 0; i < matrix.size(); ++i) {
        stack<int> stk;
        for (int j = 0; j <= matrix[0].size(); ++j) {
            if (j && matrix[i][j - 1] == '1') {
                stk.push(j);
                heights[j]++;
            } else {
                heights[j] = 0;
           
            }
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
        while (!stk.empty()) stk.pop();
    }
    return maxArea;
}

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    heights.push_back(0);
    heights.push_back(heights.size() - 1);
    stack<int> stk;
    for (int i = 0; i < heights.size(); ++i) {
        while (!stk.empty() && heights[i] < heights[stk.top()]) {
            int mid = stk.top();
            stk.pop();
            maxArea = max(maxArea, heights[mid] * (heights[i] - heights[stk.top()]));
        }
        stk.push(i);
    }
    heights.pop_back();
    return maxArea;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> matrix(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << maximalRectangle(matrix) << endl;
    return 0;
}