#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
int largestArea(std::vector<int> heights) {
    heights.push_back(0);
    // Monotonic stack to track visible elements
    std::stack<int> st;
    st.push(-1);
    int max_area = 0;
    for (int i = 0; i < (int)heights.size(); i++) {
        while (st.top() != -1 && heights[st.top()] >= heights[i]) {
            int h = heights[st.top()]; st.pop();
            int w = i - st.top() - 1;
            max_area = std::max(max_area, h * w);
        }
        st.push(i);
    }
    return max_area;
}
int main() {
    int r, c;
    if (std::cin >> r >> c) {
        std::vector<int> heights(c, 0);
        int max_area = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int val; std::cin >> val;
                heights[j] = (val == 1) ? heights[j] + 1 : 0;
            }
            max_area = std::max(max_area, largestArea(heights));
        }
        std::cout << max_area << std::endl;
    }
    return 0;
}