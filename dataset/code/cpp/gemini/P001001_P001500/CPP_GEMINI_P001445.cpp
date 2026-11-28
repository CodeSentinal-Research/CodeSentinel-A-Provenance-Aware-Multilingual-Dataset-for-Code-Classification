#include <vector>
#include <string>

class Solution {
    struct Node {
        std::string word;
        size_t idx;
    };
public:
    int numMatchingSubseq(std::string s, std::vector<std::string>& words) {
        std::vector<std::vector<Node>> heads(26);
        for (const auto& w : words) {
            heads[w[0] - 'a'].push_back({w, 0});
        }

        int ans = 0;
        for (char c : s) {
            auto cur = std::move(heads[c - 'a']);
            heads[c - 'a'].clear();

            for (auto& node : cur) {
                node.idx++;
                if (node.idx == node.word.length()) {
                    ans++;
                } else {
                    heads[node.word[node.idx] - 'a'].push_back(std::move(node));
                }
            }
        }
        return ans;
    }
};