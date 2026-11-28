#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> l1(n);
        for (int i = 0; i < n; i++) std::cin >> l1[i];
        int m; std::cin >> m;
        std::vector<int> l2(m);
        for (int i = 0; i < m; i++) std::cin >> l2[i];
        std::vector<int> res(n + m);
        std::merge(l1.begin(), l1.end(), l2.begin(), l2.end(), res.begin());
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}