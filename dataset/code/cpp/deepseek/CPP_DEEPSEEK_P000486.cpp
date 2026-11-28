Here is a C++ solution using the stack for the largest rectangle in the histogram problem. This solution has a time complexity of O(n).

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
            int height = heights[st.top()];
            st.pop();
            if (st.empty()) {
                maxArea = max(maxArea, height * i);
            } else {
                maxArea = max(maxArea, height * (i - st.top() - 1));
            }
        }
        st.push(i);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Max area is: " << largestRectangleArea(heights) << endl;
    return 0;
}

This code uses a stack to process the heights of the bars in order. For each bar, it finds the maximum area of rectangle with the bar as the shortest bar. The stack is used to keep track of the indices of the bars that can potentially form a rectangle with the current bar.