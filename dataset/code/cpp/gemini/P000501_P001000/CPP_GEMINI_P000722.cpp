#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
bool backtrack(const std::vector<int>& matchsticks, int idx, int side, int sides[4]) {
    if (idx == (int)matchsticks.size()) return true;
    for (int i = 0; i < 4; i++) {
        if (sides[i] + matchsticks[idx] <= side) {
            sides[i] += matchsticks[idx];
            if (backtrack(matchsticks, idx + 1, side, sides)) return true;
            sides[i] -= matchsticks[idx];
        }
        if (sides[i] == 0) break;
    }
    return false;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> matchsticks(n);
        int total = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> matchsticks[i];
            total += matchsticks[i];
        }
        if (total % 4 != 0 || n < 4) { std::cout << "false\n"; return 0; }
        int side = total / 4;
        std::sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > side) { std::cout << "false\n"; return 0; }
        int sides[4] = {0};
        std::cout << (backtrack(matchsticks, 0, side, sides) ? "true" : "false") << std::endl;
    }
    return 0;
}