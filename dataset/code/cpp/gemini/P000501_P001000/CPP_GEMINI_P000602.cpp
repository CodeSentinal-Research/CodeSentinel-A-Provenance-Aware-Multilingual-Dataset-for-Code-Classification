#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::vector<int> vals;
    int v;
    while (std::cin >> v) vals.push_back(v);
    if (vals.empty()) return 0;
    if (vals.size() == 1) {
        std::cout << vals[0] << std::endl;
        return 0;
    }
    std::sort(vals.begin(), vals.end());
    for (size_t i = 0; i < vals.size(); i++) {
        std::cout << vals[i] << (i + 1 == vals.size() ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}