#include <iostream>
#include <set>
#include <vector>
#include <string>
int main() {
    int q;
    if (std::cin >> q) {
        std::set<int> nums;
        while (q--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "addNum") {
                int val; std::cin >> val;
                nums.insert(val);
            } else if (cmd == "getIntervals") {
                std::vector<std::pair<int, int>> intervals;
                for (int x : nums) {
                    if (!intervals.empty() && intervals.back().second + 1 == x) {
                        intervals.back().second = x;
                    } else {
                        intervals.push_back({x, x});
                    }
                }
                for (size_t i = 0; i < intervals.size(); i++) {
                    std::cout << "[" << intervals[i].first << "," << intervals[i].second << "]" << (i + 1 == intervals.size() ? "" : " ");
                }
                std::cout << std::endl;
            }
        }
    }
    return 0;
}