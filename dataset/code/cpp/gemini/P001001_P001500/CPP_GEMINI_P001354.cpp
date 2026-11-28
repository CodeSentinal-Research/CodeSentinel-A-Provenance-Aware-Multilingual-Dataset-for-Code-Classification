#include <vector>
#include <string>
#include <climits>

class Solution {
    bool backtrack(const std::string& num, size_t idx, std::vector<int>& res) {
        if (idx == num.length() && res.size() >= 3) return true;
        for (size_t i = idx + 1; i <= num.length(); i++) {
            if (num[idx] == '0' && i > idx + 1) break;
            long long val = std::stoll(num.substr(idx, i - idx));
            if (val > INT_MAX) break;

            size_t size = res.size();
            if (size >= 2) {
                long long sum = (long long)res[size - 1] + res[size - 2];
                if (val < sum) continue;
                else if (val > sum) break;
            }

            res.push_back((int)val);
            if (backtrack(num, i, res)) return true;
            res.pop_back();
        }
        return false;
    }
public:
    std::vector<int> splitIntoFibonacci(std::string num) {
        std::vector<int> res;
        backtrack(num, 0, res);
        return res;
    }
};