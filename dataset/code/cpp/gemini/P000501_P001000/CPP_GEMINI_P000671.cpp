#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (vals[i] < vals[i - 1]) { sorted = false; break; }
        }
        std::cout << (sorted ? "true" : "false") << std::endl;
    }
    return 0;
}