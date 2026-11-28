#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int j = 0; j < m; j++) std::cin >> b[j];

        int i = n - 1, j = 0;
        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                std::swap(a[i], b[j]);
                i--; j++;
            } else {
                break;
            }
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        for (int val : a) std::cout << val << " ";
        for (int val : b) std::cout << val << " ";
        std::cout << "\n";
    }
    return 0;
}