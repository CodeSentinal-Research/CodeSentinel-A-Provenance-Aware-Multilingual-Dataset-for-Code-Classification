#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int val; std::cin >> val;
        bool first = true;
        for (int x : vals) {
            if (x != val) {
                if (!first) std::cout << " ";
                std::cout << x;
                first = false;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}