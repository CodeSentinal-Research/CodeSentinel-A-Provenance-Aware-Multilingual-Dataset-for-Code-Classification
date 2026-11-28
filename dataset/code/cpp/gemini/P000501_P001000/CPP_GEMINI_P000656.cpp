#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int main() {
    std::string s;
    std::vector<int> vals;
    while (std::cin >> s) {
        if (s != "null" && s != "#" && s != "N") vals.push_back(std::stoi(s));
    }
    std::sort(vals.begin(), vals.end());
    for (size_t i = 0; i < vals.size(); i++) {
        std::cout << vals[i] << (i + 1 == vals.size() ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}