#include <iostream>
#include <string>
#include <cctype>
int main() {
    std::string s;
    if (std::cin >> s) {
        int n = std::stoi(s);
        int d_sum = 0;
        for (char c : s) if (std::isdigit(c)) d_sum += c - '0';
        std::cout << (d_sum > 0 && n % d_sum == 0 ? "Harshad" : "Not Harshad") << std::endl;
    }
    return 0;
}