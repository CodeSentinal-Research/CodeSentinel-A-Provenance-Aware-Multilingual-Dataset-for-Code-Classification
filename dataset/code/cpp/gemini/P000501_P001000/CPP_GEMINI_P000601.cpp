#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int k; std::cin >> k;
        int width = n / k, rem = n % k;
        int cur = 0;
        for (int i = 0; i < k; i++) {
            int sz = width + (i < rem ? 1 : 0);
            if (sz == 0) {
                std::cout << "[]\n";
            } else {
                for (int j = 0; j < sz; j++) {
                    std::cout << vals[cur + j] << (j + 1 == sz ? "" : " ");
                }
                std::cout << std::endl;
                cur += sz;
            }
        }
    }
    return 0;
}