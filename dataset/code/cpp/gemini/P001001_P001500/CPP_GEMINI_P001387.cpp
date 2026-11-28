#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        std::cout << (a == b ? 1 : 0) << "\n";
    }
    return 0;
}