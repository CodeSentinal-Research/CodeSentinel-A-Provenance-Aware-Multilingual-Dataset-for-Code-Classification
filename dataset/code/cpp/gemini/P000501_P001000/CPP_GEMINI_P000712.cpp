#include <iostream>
#include <vector>
#include <algorithm>
void comb_sum(const std::vector<int>& cands, int target, int idx, std::vector<int>& cur) {
    if (target == 0) {
        for (size_t i = 0; i < cur.size(); i++) {
            std::cout << cur[i] << (i + 1 == cur.size() ? "" : " ");
        }
        std::cout << std::endl;
        return;
    }
    for (int i = idx; i < (int)cands.size(); i++) {
        if (cands[i] > target) break;
        cur.push_back(cands[i]);
        comb_sum(cands, target - cands[i], i, cur);
        cur.pop_back();
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> cands(n), cur;
        for (int i = 0; i < n; i++) std::cin >> cands[i];
        int target; std::cin >> target;
        std::sort(cands.begin(), cands.end());
        comb_sum(cands, target, 0, cur);
    }
    return 0;
}