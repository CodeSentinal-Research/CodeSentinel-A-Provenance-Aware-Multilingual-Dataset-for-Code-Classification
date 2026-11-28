#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

int main() {
    std::string text, broken;
    if (std::getline(std::cin, text) && std::getline(std::cin, broken)) {
        std::unordered_set<char> b(broken.begin(), broken.end());
        std::stringstream ss(text);
        std::string w;
        int count = 0;
        while (ss >> w) {
            bool ok = true;
            for (char c : w) {
                if (b.count(c)) { ok = false; break; }
            }
            if (ok) count++;
        }
        std::cout << count << std::endl;
    }
    return 0;
}