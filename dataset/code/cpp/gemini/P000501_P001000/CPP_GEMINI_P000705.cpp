#include <iostream>
#include <vector>
void gen_subseq(const std::vector<int>& arr, int idx, std::vector<int>& cur) {
    if (idx == (int)arr.size()) {
        for (size_t i = 0; i < cur.size(); i++) {
            std::cout << cur[i] << (i + 1 == cur.size() ? "" : " ");
        }
        std::cout << std::endl;
        return;
    }
    gen_subseq(arr, idx + 1, cur);
    cur.push_back(arr[idx]);
    gen_subseq(arr, idx + 1, cur);
    cur.pop_back();
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> nums(n), cur;
        for (int i = 0; i < n; i++) std::cin >> nums[i];
        gen_subseq(nums, 0, cur);
    }
    return 0;
}