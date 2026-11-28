#include <iostream>
#include <string>
#include <algorithm>

std::string addStrings(std::string num1, std::string num2) {
    std::string res = "";
    int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::string s1, s2;
    if (std::cin >> s1 >> s2) {
        std::cout << addStrings(s1, s2) << std::endl;
    }
    return 0;
}