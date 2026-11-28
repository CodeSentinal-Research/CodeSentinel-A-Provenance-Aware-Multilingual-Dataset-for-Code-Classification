#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
        for (int i = 0; i < n; i++) {
            long long x;
            std::cin >> x;
            pq.push(x);
        }
        long long total = 0;
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            long long cost = a + b;
            total += cost;
            pq.push(cost);
        }
        std::cout << total << "\n";
    }
    return 0;
}