#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        std::vector<int> res;
        int l = 0, r = n - 1;
        // Binary search loop to narrow down range
        while (l <= r) {
            if (l == r) res.push_back(vals[l]);
            else { res.push_back(vals[l]); res.push_back(vals[r]); }
            l++; r--;
        }
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}