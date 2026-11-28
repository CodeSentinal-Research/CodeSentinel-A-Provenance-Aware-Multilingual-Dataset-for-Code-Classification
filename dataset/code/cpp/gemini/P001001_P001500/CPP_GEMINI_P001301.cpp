#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::pair<int, int>> meetings(n);
        for (int i = 0; i < n; i++) std::cin >> meetings[i].second; // start
        for (int i = 0; i < n; i++) std::cin >> meetings[i].first;  // end

        std::sort(meetings.begin(), meetings.end());
        int count = 0, lastEnd = -1;

        for (const auto& [e, s] : meetings) {
            if (s > lastEnd) {
                count++;
                lastEnd = e;
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}