#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> l1(n);
        for (int i = 0; i < n; i++) std::cin >> l1[i];
        int m; std::cin >> m;
        std::vector<int> l2(m);
        for (int i = 0; i < m; i++) std::cin >> l2[i];
        std::cout << (l1 == l2 ? "true" : "false") << std::endl;
    }
    return 0;
}