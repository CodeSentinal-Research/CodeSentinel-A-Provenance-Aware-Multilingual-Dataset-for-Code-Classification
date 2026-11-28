#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::map<int, int> count;
        for (int x : arr1) count[x]++;

        std::vector<int> res;
        for (int x : arr2) {
            while (count[x] > 0) {
                res.push_back(x);
                count[x]--;
            }
        }

        for (auto& [x, cnt] : count) {
            while (cnt > 0) {
                res.push_back(x);
                cnt--;
            }
        }
        return res;
    }
};