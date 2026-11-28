#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::string rev = s;
        std::reverse(rev.begin(), rev.end());
        std::cout << (s == rev ? "Palindrome" : "Not Palindrome") << std::endl;
    }
    return 0;
}