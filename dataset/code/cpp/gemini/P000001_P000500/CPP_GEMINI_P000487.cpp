#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> h(n);
        for (int i = 0; i < n; i++) std::cin >> h[i];
        int l = 0, r = n - 1;
        int l_max = 0, r_max = 0;
        long long water = 0;
        while (l < r) {
            if (h[l] < h[r]) {
                if (h[l] >= l_max) l_max = h[l];
                else water += l_max - h[l];
                l++;
            } else {
                if (h[r] >= r_max) r_max = h[r];
                else water += r_max - h[r];
                r--;
            }
        }
        std::cout << water << std::endl;
    }
    return 0;
}