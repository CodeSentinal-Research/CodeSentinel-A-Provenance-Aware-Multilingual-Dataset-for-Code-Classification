#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_set<int> seen;
        int dup = -1;
        for (int i = 0; i < n; i++) {
            int v;
            std::cin >> v;
            if (seen.count(v) && dup == -1) {
                dup = v;
            }
            seen.insert(v);
        }
        std::cout << dup << std::endl;
    }
    return 0;
}