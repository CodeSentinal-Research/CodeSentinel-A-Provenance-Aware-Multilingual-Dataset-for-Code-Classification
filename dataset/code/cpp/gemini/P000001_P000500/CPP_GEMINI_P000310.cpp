#include <iostream>
#include <string>
#include <algorithm>

std::string addBinary(std::string a, std::string b) {
    std::string res = "";
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back((sum % 2) + '0');
        carry = sum / 2;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::string a, b;
    if (std::cin >> a >> b) {
        std::cout << addBinary(a, b) << std::endl;
    }
    return 0;
}