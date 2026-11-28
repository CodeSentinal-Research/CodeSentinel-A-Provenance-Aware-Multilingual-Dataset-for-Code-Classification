#include <iostream>
#include <string>
#include <vector>
int main() {
    std::string token;
    std::vector<std::string> res;
    while (std::cin >> token) {
        if (token != "null" && token != "#" && token != "N") res.push_back(token);
    }
    for (size_t i = 0; i < res.size(); i++) {
        std::cout << res[i] << (i + 1 == res.size() ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}