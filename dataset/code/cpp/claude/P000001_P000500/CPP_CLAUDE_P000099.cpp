#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> printFloydTriangle(int n) {
        std::vector<std::vector<int>> res;
        int num = 1;
        for (int i = 1; i <= n; i++) {
            std::vector<int> row;
            for (int j = 0; j < i; j++) {
                row.push_back(num++);
            }
            res.push_back(row);
        }
        return res;
    }
};
