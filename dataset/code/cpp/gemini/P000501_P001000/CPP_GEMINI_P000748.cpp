#include <iostream>
#include <vector>
void dice_rolls(int target, std::vector<int>& cur) {
    if (target == 0) {
        for (size_t i = 0; i < cur.size(); i++) {
            std::cout << cur[i] << (i + 1 == cur.size() ? "" : " ");
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 1; i <= 6 && i <= target; i++) {
        cur.push_back(i);
        dice_rolls(target - i, cur);
        cur.pop_back();
    }
}
int main() {
    int target;
    if (std::cin >> target) {
        std::vector<int> cur;
        dice_rolls(target, cur);
    }
    return 0;
}