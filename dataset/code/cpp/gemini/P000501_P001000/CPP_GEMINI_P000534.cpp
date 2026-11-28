#include <iostream>
#include <string>
#include <queue>
int main() {
    std::string s;
    if (std::cin >> s) {
        int n = s.length();
        std::queue<int> r_q, d_q;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') r_q.push(i);
            else d_q.push(i);
        }
        while (!r_q.empty() && !d_q.empty()) {
            int r_idx = r_q.front(); r_q.pop();
            int d_idx = d_q.front(); d_q.pop();
            if (r_idx < d_idx) r_q.push(r_idx + n);
            else d_q.push(d_idx + n);
        }
        std::cout << (r_q.empty() ? "Dire" : "Radiant") << std::endl;
    }
    return 0;
}