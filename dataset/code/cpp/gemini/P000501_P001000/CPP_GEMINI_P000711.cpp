#include <iostream>
#include <vector>
void comb(int n, int k, int start, std::vector<int>& cur) {
    if ((int)cur.size() == k) {
        for (size_t i = 0; i < cur.size(); i++) {
            std::cout << cur[i] << (i + 1 == cur.size() ? "" : " ");
        }
        std::cout << std::endl;
        return;
    }
    for (int i = start; i <= n; i++) {
        cur.push_back(i);
        comb(n, k, i + 1, cur);
        cur.pop_back();
    }
}
int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::vector<int> cur;
        comb(n, k, 1, cur);
    }
    return 0;
}