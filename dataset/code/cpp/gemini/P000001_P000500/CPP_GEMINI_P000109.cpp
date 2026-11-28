#include <iostream>
#include <vector>
int main() {
    int n;
    long long target;
    if (std::cin >> n >> target) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            long long val;
            std::cin >> val;
            if (val == target && idx == -1) idx = i;
        }
        std::cout << idx << std::endl;
    }
    return 0;
}