#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<int, int>> acts(n);
        for (int i = 0; i < n; i++) std::cin >> acts[i].second; // start
        for (int i = 0; i < n; i++) std::cin >> acts[i].first;  // end

        std::sort(acts.begin(), acts.end());
        int count = 0, lastEnd = -1;
        for (const auto& [e, s] : acts) {
            if (s >= lastEnd) {
                count++;
                lastEnd = e;
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}