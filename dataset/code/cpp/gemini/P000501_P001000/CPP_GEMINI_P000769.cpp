#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
std::unordered_map<std::string, bool> memo;
bool is_scramble(std::string s1, std::string s2) {
    if (s1 == s2) return true;
    std::string key = s1 + "#" + s2;
    if (memo.count(key)) return memo[key];
    std::string t1 = s1, t2 = s2;
    std::sort(t1.begin(), t1.end());
    std::sort(t2.begin(), t2.end());
    if (t1 != t2) return memo[key] = false;
    int n = s1.length();
    for (int i = 1; i < n; i++) {
        if ((is_scramble(s1.substr(0, i), s2.substr(0, i)) && is_scramble(s1.substr(i), s2.substr(i))) ||
            (is_scramble(s1.substr(0, i), s2.substr(n - i)) && is_scramble(s1.substr(i), s2.substr(0, n - i)))) {
            return memo[key] = true;
        }
    }
    return memo[key] = false;
}
int main() {
    std::string s1, s2;
    if (std::cin >> s1 >> s2) {
        std::cout << (is_scramble(s1, s2) ? "true" : "false") << std::endl;
    }
    return 0;
}