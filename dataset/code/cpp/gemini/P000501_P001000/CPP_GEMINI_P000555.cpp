#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
int main() {
    int n, p, b;
    if (std::cin >> n >> p >> b) {
        std::vector<bool> is_banned(n, false);
        for (int i = 0; i < b; i++) {
            int x; std::cin >> x;
            is_banned[x] = true;
        }
        int k; std::cin >> k;
        std::vector<int> res(n, -1);
        res[p] = 0;
        std::set<int> unvisited[2];
        for (int i = 0; i < n; i++) {
            if (i != p && !is_banned[i]) unvisited[i % 2].insert(i);
        }
        std::queue<int> q;
        q.push(p);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int min_idx = std::max(cur - k + 1, k - 1 - cur);
            int max_idx = std::min(cur + k - 1, 2 * n - k - 1 - cur);
            int parity = min_idx % 2;
            auto it = unvisited[parity].lower_bound(min_idx);
            std::vector<int> to_remove;
            while (it != unvisited[parity].end() && *it <= max_idx) {
                res[*it] = res[cur] + 1;
                q.push(*it);
                to_remove.push_back(*it);
                it++;
            }
            for (int x : to_remove) unvisited[parity].erase(x);
        }
        for (int i = 0; i < n; i++) std::cout << res[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}