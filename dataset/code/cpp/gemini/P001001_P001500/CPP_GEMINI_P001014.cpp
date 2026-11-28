#include <iostream>
#include <vector>
#include <queue>

struct Element {
    int val, r, c;
    bool operator>(const Element& o) const { return val > o.val; }
};

int main() {
    int k, n;
    if (std::cin >> k >> n && k > 0 && n > 0) {
        std::vector<std::vector<int>> arrays(k, std::vector<int>(n));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) std::cin >> arrays[i][j];
        }
        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;
        for (int i = 0; i < k; i++) {
            pq.push({arrays[i][0], i, 0});
        }
        std::vector<int> res;
        while (!pq.empty()) {
            auto [val, r, c] = pq.top();
            pq.pop();
            res.push_back(val);
            if (c + 1 < n) {
                pq.push({arrays[r][c + 1], r, c + 1});
            }
        }
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}