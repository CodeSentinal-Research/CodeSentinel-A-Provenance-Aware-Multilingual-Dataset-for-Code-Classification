#include <iostream>
#include <vector>
#include <unordered_set>
int main() {
    int n;
    long long target;
    if (std::cin >> n >> target) {
        std::unordered_set<long long> set;
        for (int i = 0; i < n; i++) {
            long long val;
            std::cin >> val;
            long long diff = target - val;
            if (set.count(diff)) {
                std::cout << diff << " " << val << std::endl;
                return 0;
            }
            set.insert(val);
        }
        std::cout << "No Pair" << std::endl;
    }
    return 0;
}