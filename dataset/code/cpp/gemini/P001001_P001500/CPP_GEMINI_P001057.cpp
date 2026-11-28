#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

int main() {
    int n, k;
    if (std::cin >> n >> k && n > 0) {
        std::unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            int x; std::cin >> x;
            count[x]++;
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (const auto& [val, cnt] : count) {
            if (cnt > 1) pq.push(cnt - 1);
        }
        while (!pq.empty() && k > 0) {
            int c = pq.top(); pq.pop();
            if (k >= c) k -= c;
            else {
                c -= k;
                k = 0;
                pq.push(c);
            }
        }
        int distinct = count.size();
        if (k > 0) distinct -= k;
        std::cout << std::max(0, distinct) << "\n";
    }
    return 0;
}