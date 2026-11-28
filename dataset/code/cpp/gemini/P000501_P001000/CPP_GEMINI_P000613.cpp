#include <iostream>
#include <vector>
#include <unordered_set>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> res;
        std::unordered_set<int> seen;
        for (int i = 0; i < n; i++) {
            int x; std::cin >> x;
            if (!seen.count(x)) {
                seen.insert(x);
                res.push_back(x);
            }
        }
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}