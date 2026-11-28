#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        int passes = 0;
        while (!nums.empty()) {
            passes++;
            std::vector<int> rem;
            int last = -2e9;
            for (int x : nums) {
                if (x > last) {
                    last = x;
                } else {
                    rem.push_back(x);
                }
            }
            nums = rem;
        }
        std::cout << passes << std::endl;
    }
    return 0;
}