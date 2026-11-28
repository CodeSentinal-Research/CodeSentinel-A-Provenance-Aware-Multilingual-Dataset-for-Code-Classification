#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        std::unordered_map<int, int> counts;
        for (int i = 0; i < n; i++) {
            std::cin >> vals[i];
            counts[vals[i]]++;
        }
        bool first = true;
        for (int x : vals) {
            if (counts[x] == 1) {
                if (!first) std::cout << " ";
                std::cout << x;
                first = false;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}