#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
void gen_subseq(const std::string& s, int idx, std::string cur, std::vector<std::string>& res) {
    if (idx == (int)s.length()) {
        res.push_back(cur);
        return;
    }
    gen_subseq(s, idx + 1, cur, res);
    gen_subseq(s, idx + 1, cur + s[idx], res);
}
int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<std::string> res;
        gen_subseq(s, 0, "", res);
        std::sort(res.begin(), res.end());
        for (const auto& str : res) std::cout << str << std::endl;
    }
    return 0;
}