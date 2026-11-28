#include <string>
#include <vector>

class Codec {
public:
    std::string encode(std::vector<std::string>& strs) {
        std::string res = "";
        for (const auto& s : strs) {
            res += std::to_string(s.size()) + "#" + s;
        }
        return res;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> res;
        size_t i = 0;
        while (i < s.size()) {
            size_t j = s.find('#', i);
            int len = std::stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return res;
    }
};