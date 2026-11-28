#include <iostream>
#include <string>
#include <vector>
int main() {
    std::string num;
    int k;
    if (std::cin >> num >> k) {
        std::string st = "";
        for (char c : num) {
            while (k > 0 && !st.empty() && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        int i = 0;
        while (i < (int)st.length() && st[i] == '0') i++;
        std::string res = st.substr(i);
        std::cout << (res.empty() ? "0" : res) << std::endl;
    }
    return 0;
}