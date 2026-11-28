#include <iostream>
#include <string>

int main() {
    std::string s;
    char c;
    if (std::cin >> s >> c) {
        int count = 0;
        for (char ch : s) if (ch == c) count++;
        std::cout << count << std::endl;
    }
    return 0;
}