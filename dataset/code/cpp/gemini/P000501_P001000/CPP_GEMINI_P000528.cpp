#include <iostream>
#include <string>
int main() {
    std::string s;
    if (std::cin >> s) {
        int l = 0, r = (int)s.length() - 1;
        // Binary search loop to narrow down range
        while (l <= r && s[l] == 'L') l++;
        while (r >= l && s[r] == 'R') r--;
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] != 'S') ans++;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}