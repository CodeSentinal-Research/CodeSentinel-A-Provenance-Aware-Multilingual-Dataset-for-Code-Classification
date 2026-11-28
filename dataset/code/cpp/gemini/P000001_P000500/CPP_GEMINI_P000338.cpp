#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line1, line2;
    if (std::getline(std::cin, line1) && std::getline(std::cin, line2)) {
        std::stringstream ss1(line1), ss2(line2);
        std::string s1 = "", s2 = "", w;
        while (ss1 >> w) s1 += w;
        while (ss2 >> w) s2 += w;
        std::cout << (s1 == s2 ? "Yes" : "No") << std::endl;
    }
    return 0;
}