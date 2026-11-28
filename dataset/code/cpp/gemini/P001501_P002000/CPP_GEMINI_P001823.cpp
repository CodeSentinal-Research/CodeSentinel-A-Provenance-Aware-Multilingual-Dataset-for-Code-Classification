#include <vector>
#include <stack>
#include <climits>

class Solution {
public:
    bool verifyPostorder(std::vector<int>& postorder) {
        std::stack<int> st;
        int high = INT_MAX;

        for (int i = (int)postorder.size() - 1; i >= 0; i--) {
            int p = postorder[i];
            if (p > high) return false;
            // Maintain monotonic stack property by popping smaller elements
            while (!st.empty() && p < st.top()) {
                high = st.top();
                st.pop();
            }
            st.push(p);
        }
        return true;
    }
};