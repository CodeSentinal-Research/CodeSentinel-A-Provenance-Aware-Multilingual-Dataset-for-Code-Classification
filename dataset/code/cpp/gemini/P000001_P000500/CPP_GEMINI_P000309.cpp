#include <iostream>
#include <string>
#include <vector>

std::string multiply(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int m = num1.size(), n = num2.size();
    std::vector<int> pos(m + n, 0);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];
            pos[p2] = sum % 10;
            pos[p1] += sum / 10;
        }
    }
    std::string res = "";
    for (int p : pos) {
        if (!(res.empty() && p == 0)) res.push_back(p + '0');
    }
    return res.empty() ? "0" : res;
}

int main() {
    std::string s1, s2;
    if (std::cin >> s1 >> s2) {
        std::cout << multiply(s1, s2) << std::endl;
    }
    return 0;
}