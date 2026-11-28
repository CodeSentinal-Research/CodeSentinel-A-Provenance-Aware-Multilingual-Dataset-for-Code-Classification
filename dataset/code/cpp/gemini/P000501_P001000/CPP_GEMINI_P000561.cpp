#include <iostream>
#include <string>
#include <queue>
#include <vector>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::vector<int> count(26, 0);
        std::queue<char> q;
        std::string res = "";
        for (char c : s) {
            count[c - 'a']++;
            q.push(c);
            while (!q.empty() && count[q.front() - 'a'] > 1) q.pop();
            res += q.empty() ? '#' : q.front();
        }
        std::cout << res << std::endl;
    }
    return 0;
}