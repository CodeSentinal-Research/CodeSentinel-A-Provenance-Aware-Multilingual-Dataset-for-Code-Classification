#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n);
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        std::sort(nums.begin(), nums.end());
        do {
            for (int i = 0; i < n; i++) std::cout << nums[i] << (i == n - 1 ? "" : " ");
            std::cout << std::endl;
        } while (std::next_permutation(nums.begin(), nums.end()));
    }
    return 0;
}