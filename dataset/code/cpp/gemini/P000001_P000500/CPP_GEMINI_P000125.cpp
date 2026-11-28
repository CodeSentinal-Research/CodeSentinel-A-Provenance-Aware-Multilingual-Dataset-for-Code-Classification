#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    int n;
    long long target;
    if (std::cin >> n >> target) {
        std::unordered_map<long long, int> map;
        for (int i = 0; i < n; i++) {
            long long val;
            std::cin >> val;
            long long diff = target - val;
            if (map.count(diff)) {
                std::cout << map[diff] << " " << i << std::endl;
                return 0;
            }
            map[val] = i;
        }
    }
    return 0;
}