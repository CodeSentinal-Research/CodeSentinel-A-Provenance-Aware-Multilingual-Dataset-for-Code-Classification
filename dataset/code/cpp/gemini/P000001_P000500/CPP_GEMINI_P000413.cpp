#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
struct Emp { std::string name, dept, status; };
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<Emp> emps(n);
        for (int i = 0; i < n; i++) std::cin >> emps[i].name >> emps[i].dept >> emps[i].status;
        std::string dept;
        std::cin >> dept;
        for (const auto& e : emps) {
            std::string st = e.status;
            std::transform(st.begin(), st.end(), st.begin(), ::tolower);
            if (e.dept == dept && (st == "active" || st == "true" || st == "1" || st == "yes")) {
                std::cout << e.name << "\n";
            }
        }
    }
    return 0;
}