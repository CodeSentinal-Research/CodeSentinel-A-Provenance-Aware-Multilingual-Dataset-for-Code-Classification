#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        long long k;
        std::cin >> k;
        std::vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        std::deque<int> q;
        int min_len = n + 1;
        for (int i = 0; i <= n; i++) {
            while (!q.empty() && prefix[i] - prefix[q.front()] >= k) {
                min_len = std::min(min_len, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && prefix[q.back()] >= prefix[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        std::cout << (min_len <= n ? min_len : -1) << std::endl;
    }
    return 0;
}