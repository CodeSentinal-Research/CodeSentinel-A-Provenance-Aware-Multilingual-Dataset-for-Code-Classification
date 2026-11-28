#include <iostream>
#include <string>

bool isPalindrome(const std::string& s, int i, int j) {
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

bool check(const std::string& a, const std::string& b) {
    int i = 0, j = (int)a.length() - 1;
    while (i < j && a[i] == b[j]) {
        i++;
        j--;
    }
    return isPalindrome(a, i, j) || isPalindrome(b, i, j);
}

int main() {
    std::string a, b;
    if (std::cin >> a >> b) {
        std::cout << (check(a, b) || check(b, a) ? "Yes" : "No") << std::endl;
    }
    return 0;
}