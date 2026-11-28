#include <iostream>
#include <vector>
#include <string>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        bool is_pal = true;
        for (int i = 0; i < n / 2; i++) {
            if (vals[i] != vals[n - 1 - i]) { is_pal = false; break; }
        }
        std::cout << (is_pal ? "true" : "false") << std::endl;
    }
    return 0;
}