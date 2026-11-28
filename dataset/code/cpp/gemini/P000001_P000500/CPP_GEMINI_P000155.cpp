#include <iostream>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        int max_cnt = 0, curr_cnt = 0;
        for (int i = 0; i < n; i++) {
            int val;
            std::cin >> val;
            if (val == 1) {
                curr_cnt++;
                max_cnt = std::max(max_cnt, curr_cnt);
            } else {
                curr_cnt = 0;
            }
        }
        std::cout << max_cnt << std::endl;
    }
    return 0;
}