#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        long long cur = 0;
        int longest = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            cur += x;
            if (cur < 0) longest = i + 1;
        }
        std::cout << longest << "\n";
    }
    return 0;
}