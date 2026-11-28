#include <vector>
#include <stack>
#include <climits>

class Solution {
public:
    bool verifyPreorder(std::vector<int>& preorder) {
        std::stack<int> st;
        int low = INT_MIN;

        for (int p : preorder) {
            if (p < low) return false;
            // Maintain monotonic stack property by popping smaller elements
            while (!st.empty() && p > st.top()) {
                low = st.top();
                st.pop();
            }
            st.push(p);
        }
        return true;
    }
};