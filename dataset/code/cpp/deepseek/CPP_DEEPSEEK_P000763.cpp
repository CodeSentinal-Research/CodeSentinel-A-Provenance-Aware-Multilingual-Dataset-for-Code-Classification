Here's a simple C++ solution for the given problem:

#include <iostream>
#include <string>

bool isMatch(std::string s, std::string p) {
    if (p.empty()) return s.empty();

    bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

    if (p.length() > 1) {
        return first_match && isMatch(s.substr(1), p.substr(1));
    } else {
        return first_match && isMatch(s.substr(1), p);
    }
}

int main() {
    std::string s, p;
    std::cin >> s >> p;

    if (isMatch(s, p)) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }

    return 0;
}

This program works by using recursion to check the entire string against the pattern. It first checks if the pattern is empty. If it is, it means we've exhausted all characters in the pattern, so the string must be also be empty. If the pattern is not empty, it checks if the first character of the pattern matches the first character of the string. If they match, it recursively checks the rest of the string and the rest of the pattern. If the first character of the pattern matches, it continues with the rest of the string and the rest of the pattern. If they don't match, it returns false.