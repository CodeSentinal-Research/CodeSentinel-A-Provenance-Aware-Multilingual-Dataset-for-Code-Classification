#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> res(n, 0);
        std::vector<int> st;
        int prev_time = 0;
        std::string log;
        while (std::cin >> log) {
            std::stringstream ss(log);
            std::string id_str, action, time_str;
            std::getline(ss, id_str, ':');
            std::getline(ss, action, ':');
            std::getline(ss, time_str, ':');
            int fn_id = std::stoi(id_str);
            int timestamp = std::stoi(time_str);
            if (action == "start") {
                if (!st.empty()) {
                    res[st.back()] += timestamp - prev_time;
                }
                st.push_back(fn_id);
                prev_time = timestamp;
            } else {
                res[st.back()] += timestamp - prev_time + 1;
                st.pop_back();
                prev_time = timestamp + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << res[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}