#include <iostream>
#include <string>
#include <algorithm>

std::string convertToTitle(long long columnNumber) {
    std::string res = "";
    while (columnNumber > 0) {
        columnNumber--;
        res.push_back('A' + (columnNumber % 26));
        columnNumber /= 26;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << convertToTitle(n) << std::endl;
    }
    return 0;
}