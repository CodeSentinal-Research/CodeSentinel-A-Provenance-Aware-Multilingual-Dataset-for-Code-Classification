#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int max_area = 0;
    for(int i=0; i<=heights.size(); i++) {
        int h = (i == heights.size()) ? 0 : heights[i];
        while(!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, height * width);
        }
        st.push(i);
    }
    return max_area;
}
int main() {
    int n; cin >> n;
    vector<int> heights(n);
    for(int i=0; i<n; i++) cin >> heights[i];
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
