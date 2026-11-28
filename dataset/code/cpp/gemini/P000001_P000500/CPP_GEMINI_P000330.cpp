#include <iostream>
#include <string>
#include <vector>

std::string addBoldTag(std::string s, std::vector<std::string>& words) {
    int n = s.length();
    std::vector<bool> bold(n, false);
    for (const auto& w : words) {
        size_t pos = s.find(w);
        while (pos != std::string::npos) {
            for (size_t i = pos; i < pos + w.length(); i++) bold[i] = true;
            pos = s.find(w, pos + 1);
        }
    }
    std::string res = "";
    for (int i = 0; i < n; ) {
        if (bold[i]) {
            res += "<b>";
            while (i < n && bold[i]) {
                res += s[i++];
            }
            res += "</b>";
        } else {
            res += s[i++];
        }
    }
    return res;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<std::string> words;
        std::string w;
        while (std::cin >> w) words.push_back(w);
        std::cout << addBoldTag(s, words) << std::endl;
    }
    return 0;
}