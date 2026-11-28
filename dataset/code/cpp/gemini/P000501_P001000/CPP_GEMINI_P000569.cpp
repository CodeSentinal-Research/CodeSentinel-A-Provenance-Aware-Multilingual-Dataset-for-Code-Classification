#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> q(n);
        for (int i = 0; i < n; i++) std::cin >> q[i];
        std::reverse(q.begin(), q.end());
        for (int i = 0; i < n; i++) std::cout << q[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}