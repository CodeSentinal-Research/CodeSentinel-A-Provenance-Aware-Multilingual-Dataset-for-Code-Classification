#include <iostream>
#include <vector>
#include <string>
int main() {
    int m;
    if (std::cin >> m) {
        std::vector<int> target(m);
        for (int i = 0; i < m; i++) std::cin >> target[i];
        int n;
        std::cin >> n;
        int target_idx = 0;
        for (int i = 1; i <= n; i++) {
            if (target_idx == m) break;
            std::cout << "Push\n";
            if (target[target_idx] == i) target_idx++;
            else std::cout << "Pop\n";
        }
    }
    return 0;
}