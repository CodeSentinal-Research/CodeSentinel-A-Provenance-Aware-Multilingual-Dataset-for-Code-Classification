#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int w, h, n;
    if (std::cin >> w >> h >> n) {
        std::vector<int> xs = {0, w + 1};
        std::vector<int> ys = {0, h + 1};

        for (int i = 0; i < n; i++) {
            int x, y;
            std::cin >> x >> y;
            xs.push_back(x);
            ys.push_back(y);
        }

        std::sort(xs.begin(), xs.end());
        std::sort(ys.begin(), ys.end());

        int maxDx = 0, maxDy = 0;
        for (size_t i = 1; i < xs.size(); i++) {
            maxDx = std::max(maxDx, xs[i] - xs[i - 1] - 1);
            maxDy = std::max(maxDy, ys[i] - ys[i - 1] - 1);
        }
        std::cout << (long long)maxDx * maxDy << "\n";
    }
    return 0;
}