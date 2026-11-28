#include <iostream>
#include <unordered_set>
int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_set<int> vals;
        for (int i = 0; i < n; i++) {
            int x; std::cin >> x; vals.insert(x);
        }
        int target; std::cin >> target;
        std::cout << (vals.count(target) ? "true" : "false") << std::endl;
    }
    return 0;
}