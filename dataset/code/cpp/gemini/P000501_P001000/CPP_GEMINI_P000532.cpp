#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> t(n);
        for (int i = 0; i < n; i++) std::cin >> t[i];
        int k;
        std::cin >> k;
        int time = 0;
        for (int i = 0; i < n; i++) {
            time += (i <= k) ? std::min(t[i], t[k]) : std::min(t[i], t[k] - 1);
        }
        std::cout << time << std::endl;
    }
    return 0;
}