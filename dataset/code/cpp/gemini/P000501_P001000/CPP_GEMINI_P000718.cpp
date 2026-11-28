#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::vector<std::string> gray_code(int n) {
    if (n == 0) return {"0"};
    if (n == 1) return {"0", "1"};
    auto prev = gray_code(n - 1);
    std::vector<std::string> res;
    for (const auto& s : prev) res.push_back("0" + s);
    for (int i = (int)prev.size() - 1; i >= 0; i--) res.push_back("1" + prev[i]);
    return res;
}
int main() {
    int n;
    if (std::cin >> n) {
        for (const auto& s : gray_code(n)) std::cout << s << std::endl;
    }
    return 0;
}