#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> heights(n, 0);
    int max_area = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == '1') heights[j]++;
            else heights[j] = 0;
        }
        stack<int> st;
        for(int j=0; j<=n; j++) {
            int h = (j == n) ? 0 : heights[j];
            while(!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()]; st.pop();
                int width = st.empty() ? j : j - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(j);
        }
    }
    return max_area;
}
int main() {
    int r, c; cin >> r >> c;
    vector<vector<char>> matrix(r, vector<char>(c));
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin >> matrix[i][j];
    cout << maximalRectangle(matrix) << endl;
    return 0;
}
