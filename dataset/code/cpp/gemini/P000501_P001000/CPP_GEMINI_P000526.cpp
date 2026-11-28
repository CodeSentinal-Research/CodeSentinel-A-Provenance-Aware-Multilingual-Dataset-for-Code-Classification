#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
int main() {
    std::string formula;
    if (std::cin >> formula) {
        std::vector<std::map<std::string, int>> st;
        st.push_back({});
        int i = 0, n = formula.length();
        while (i < n) {
            if (formula[i] == '(') {
                st.push_back({});
                i++;
            } else if (formula[i] == ')') {
                i++;
                int i_start = i;
                while (i < n && std::isdigit(formula[i])) i++;
                int mult = (i_start == i) ? 1 : std::stoi(formula.substr(i_start, i - i_start));
                auto top = st.back(); st.pop_back();
                for (auto const& [atom, cnt] : top) {
                    st.back()[atom] += cnt * mult;
                }
            } else {
                int i_start = i++;
                while (i < n && std::islower(formula[i])) i++;
                std::string atom = formula.substr(i_start, i - i_start);
                i_start = i;
                while (i < n && std::isdigit(formula[i])) i++;
                int cnt = (i_start == i) ? 1 : std::stoi(formula.substr(i_start, i - i_start));
                st.back()[atom] += cnt;
            }
        }
        std::string res = "";
        for (auto const& [atom, cnt] : st[0]) {
            res += atom + (cnt > 1 ? std::to_string(cnt) : "");
        }
        std::cout << res << std::endl;
    }
    return 0;
}