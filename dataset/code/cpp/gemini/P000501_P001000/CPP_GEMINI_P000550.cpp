#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> p(n), d(n);
        for (int i = 0; i < n; i++) std::cin >> p[i];
        for (int i = 0; i < n; i++) std::cin >> d[i];
        long long total = 0, curr = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int diff = p[i] - d[i];
            total += diff;
            curr += diff;
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        std::cout << (total >= 0 ? start : -1) << std::endl;
    }
    return 0;
}