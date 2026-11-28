#include <iostream>
#include <vector>

int main() {
    long long x;
    int k;
    if (std::cin >> x >> k && k > 0) {
        std::vector<long long> num(k), rem(k);
        for (int i = 0; i < k; i++) std::cin >> num[i];
        for (int i = 0; i < k; i++) std::cin >> rem[i];
        bool ok = true;
        for (int i = 0; i < k; i++) {
            if (x % num[i] != rem[i]) {
                ok = false;
                break;
            }
        }
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}