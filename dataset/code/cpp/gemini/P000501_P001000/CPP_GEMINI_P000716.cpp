#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void letter_comb(const std::string& digits, int idx, std::string cur) {
    if (idx == (int)digits.length()) {
        std::cout << cur << std::endl;
        return;
    }
    int d = digits[idx] - '0';
    for (char c : pad[d]) {
        letter_comb(digits, idx + 1, cur + c);
    }
}
int main() {
    std::string digits;
    if (std::cin >> digits) {
        letter_comb(digits, 0, "");
    }
    return 0;
}