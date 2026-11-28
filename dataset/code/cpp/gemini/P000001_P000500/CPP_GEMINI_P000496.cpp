#include <iostream>
#include <vector>
#include <stack>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<long long> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        long long MOD = 1000000007;
        std::vector<int> prev_less(n, -1), next_less(n, n);
        // Monotonic stack to track visible elements
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            // Pop smaller elements that are blocked from view
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            prev_less[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop smaller elements that are blocked from view
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            next_less[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev_less[i];
            long long right = next_less[i] - i;
            ans = (ans + arr[i] * left % MOD * right % MOD) % MOD;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}