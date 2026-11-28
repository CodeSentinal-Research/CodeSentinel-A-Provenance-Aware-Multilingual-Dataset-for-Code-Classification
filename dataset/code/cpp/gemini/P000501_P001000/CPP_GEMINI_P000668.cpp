#include <iostream>
#include <vector>
int main() {
    int size;
    if (std::cin >> size) {
        std::vector<int> vals(size);
        for (int i = 0; i < size; i++) std::cin >> vals[i];
        int m, n; std::cin >> m >> n;
        std::vector<int> res;
        int cur = 0;
        while (cur < size) {
            for (int i = 0; i < m && cur + i < size; i++) {
                res.push_back(vals[cur + i]);
            }
            cur += m + n;
        }
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}