#include <iostream>
#include <string>
#include <vector>
#include <cctype>
int main() {
    std::string token;
    std::vector<int> nums;
    std::vector<std::string> ops;
    while (std::cin >> token) {
        if (token == "next()" || token == "hasNext()") {
            ops.push_back(token);
        } else {
            // parse integers out of nested list structure
            int i = 0;
            while (i < (int)token.length()) {
                if (std::isdigit(token[i]) || (token[i] == '-' && i + 1 < (int)token.length() && std::isdigit(token[i+1]))) {
                    int sign = 1;
                    if (token[i] == '-') { sign = -1; i++; }
                    int val = 0;
                    while (i < (int)token.length() && std::isdigit(token[i])) {
                        val = val * 10 + (token[i] - '0');
                        i++;
                    }
                    nums.push_back(sign * val);
                } else {
                    i++;
                }
            }
        }
    }
    int idx = 0;
    for (const auto& op : ops) {
        if (op == "next()") {
            if (idx < (int)nums.size()) std::cout << nums[idx++] << std::endl;
        } else if (op == "hasNext()") {
            std::cout << (idx < (int)nums.size() ? "true" : "false") << std::endl;
        }
    }
    return 0;
}