#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
        std::unordered_map<std::string, int> map1;
        for (size_t i = 0; i < list1.size(); i++) map1[list1[i]] = i;

        int minSum = INT_MAX;
        std::vector<std::string> res;

        for (size_t j = 0; j < list2.size(); j++) {
            if (map1.count(list2[j])) {
                int sum = map1[list2[j]] + j;
                if (sum < minSum) {
                    minSum = sum;
                    res.clear();
                    res.push_back(list2[j]);
                } else if (sum == minSum) {
                    res.push_back(list2[j]);
                }
            }
        }
        return res;
    }
};