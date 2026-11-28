#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

int main() {
    int n, m, k;
    if (std::cin >> n >> m >> k) {
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < m; i++) std::cin >> b[i];
        std::sort(a.rbegin(), a.rend());
        std::sort(b.rbegin(), b.rend());

        std::priority_queue<std::tuple<int, int, int>> pq;
        std::set<std::pair<int, int>> visited;
        pq.push({a[0] + b[0], 0, 0});
        visited.insert({0, 0});

        std::vector<int> res;
        while (!pq.empty() && (int)res.size() < k) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            res.push_back(sum);
            if (i + 1 < n && visited.insert({i + 1, j}).second) {
                pq.push({a[i + 1] + b[j], i + 1, j});
            }
            if (j + 1 < m && visited.insert({i, j + 1}).second) {
                pq.push({a[i] + b[j + 1], i, j + 1});
            }
        }
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}