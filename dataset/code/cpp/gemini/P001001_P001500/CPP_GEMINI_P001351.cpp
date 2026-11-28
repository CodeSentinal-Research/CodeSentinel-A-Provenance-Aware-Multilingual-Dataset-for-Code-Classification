#include <string>
#include <vector>

class CombinationIterator {
    std::vector<std::string> combinations;
    size_t idx = 0;

    void backtrack(const std::string& chars, int len, int start, std::string cur) {
        if ((int)cur.length() == len) {
            combinations.push_back(cur);
            return;
        }
        for (size_t i = start; i < chars.length(); i++) {
            backtrack(chars, len, i + 1, cur + chars[i]);
        }
    }
public:
    CombinationIterator(std::string characters, int combinationLength) {
        backtrack(characters, combinationLength, 0, "");
    }

    std::string next() {
        return combinations[idx++];
    }

    bool hasNext() {
        return idx < combinations.size();
    }
};