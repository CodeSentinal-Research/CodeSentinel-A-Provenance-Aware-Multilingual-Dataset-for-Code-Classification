#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<int, int>> intervals(n);
        for (int i = 0; i < n; i++) std::cin >> intervals[i].first >> intervals[i].second;

        std::sort(intervals.begin(), intervals.end());
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (const auto& [s, e] : intervals) {
            if (!pq.empty() && pq.top() <= s) {
                pq.pop();
            }
            pq.push(e);
        }
        std::cout << pq.size() << "\n";
    }
    return 0;
}