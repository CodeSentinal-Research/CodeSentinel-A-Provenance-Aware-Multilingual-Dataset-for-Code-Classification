#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    if (std::cin >> n) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
        for (int i = 0; i < n; i++) {
            long long x;
            std::cin >> x;
            pq.push(x);
        }
        long long totalCost = 0;
        while (pq.size() > 1) {
            long long first = pq.top(); pq.pop();
            long long second = pq.top(); pq.pop();
            long long cost = first + second;
            totalCost += cost;
            pq.push(cost);
        }
        std::cout << totalCost << "\n";
    }
    return 0;
}