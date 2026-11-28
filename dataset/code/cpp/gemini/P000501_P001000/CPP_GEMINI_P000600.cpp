#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        std::vector<int> res;
        for (int i = 0; i < n; i += 2) res.push_back(vals[i]);
        for (int i = 1; i < n; i += 2) res.push_back(vals[i]);
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}