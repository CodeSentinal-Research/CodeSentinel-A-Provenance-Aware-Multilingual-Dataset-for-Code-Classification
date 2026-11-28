#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

bool isValid(const std::string& s) {
    int cnt = 0;
    for (char c : s) {
        if (c == '(') cnt++;
        else if (c == ')') {
            cnt--;
            if (cnt < 0) return false;
        }
    }
    return cnt == 0;
}

int main() {
    std::string s;
    if (std::cin >> s) {
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;
        std::vector<std::string> res;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                std::string curr = q.front(); q.pop();
                if (isValid(curr)) {
                    res.push_back(curr);
                    found = true;
                }
                if (!found) {
                    for (size_t j = 0; j < curr.length(); j++) {
                        if (curr[j] == '(' || curr[j] == ')') {
                            std::string nextStr = curr.substr(0, j) + curr.substr(j + 1);
                            if (!visited.count(nextStr)) {
                                visited.insert(nextStr);
                                q.push(nextStr);
                            }
                        }
                    }
                }
            }
            if (found) break;
        }
        for (const auto& str : res) {
            std::cout << str << "\n";
        }
    }
    return 0;
}