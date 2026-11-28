#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];

        std::unordered_map<int, int> map;
        std::vector<int> res;

        for (int i = 0; i < n; i++) {
            map[arr[i]]++;
            if (i >= k) {
                int out = arr[i - k];
                if (--map[out] == 0) map.erase(out);
            }
            if (i >= k - 1) {
                res.push_back(map.size());
            }
        }

        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}