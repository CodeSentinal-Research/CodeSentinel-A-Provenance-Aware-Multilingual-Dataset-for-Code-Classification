#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n), res;
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int cur_sum = 0;
        for (int i = 1; i < n; i++) {
            if (vals[i] == 0) {
                res.push_back(cur_sum);
                cur_sum = 0;
            } else {
                cur_sum += vals[i];
            }
        }
        for (size_t i = 0; i < res.size(); i++) {
            std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}