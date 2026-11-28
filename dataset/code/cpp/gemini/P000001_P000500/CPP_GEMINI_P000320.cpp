#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    char c;
    if (std::cin >> s >> c) {
        int n = s.length();
        std::vector<int> res(n, 1e9);
        int prev = -1e9;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) prev = i;
            res[i] = i - prev;
        }
        prev = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) prev = i;
            res[i] = std::min(res[i], prev - i);
        }
        for (int i = 0; i < n; i++) {
            std::cout << res[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}