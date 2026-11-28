#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<int> res(n, 0);
        // Monotonic stack to track visible elements
        std::stack<int> st;
        int prev_time = 0;
        for (int i = 0; i < m; i++) {
            std::string log;
            std::cin >> log;
            std::stringstream ss(log);
            std::string s_fid, typ, s_time;
            std::getline(ss, s_fid, ':');
            std::getline(ss, typ, ':');
            std::getline(ss, s_time, ':');
            int fid = std::stoi(s_fid);
            int time = std::stoi(s_time);
            if (typ == "start") {
                // Can also see the next taller person
                if (!st.empty()) res[st.top()] += time - prev_time;
                st.push(fid);
                prev_time = time;
            } else {
                res[st.top()] += time - prev_time + 1;
                st.pop();
                prev_time = time + 1;
            }
        }
        for (int i = 0; i < n; i++) std::cout << res[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}