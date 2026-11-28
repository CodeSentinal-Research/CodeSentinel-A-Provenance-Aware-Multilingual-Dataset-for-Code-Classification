#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int compareVersion(std::string v1, std::string v2) {
    int i = 0, j = 0, n1 = v1.length(), n2 = v2.length();
    while (i < n1 || j < n2) {
        int num1 = 0, num2 = 0;
        while (i < n1 && v1[i] != '.') {
            num1 = num1 * 10 + (v1[i++] - '0');
        }
        while (j < n2 && v2[j] != '.') {
            num2 = num2 * 10 + (v2[j++] - '0');
        }
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
        i++;
        j++;
    }
    return 0;
}

int main() {
    std::string v1, v2;
    if (std::cin >> v1 >> v2) {
        std::cout << compareVersion(v1, v2) << std::endl;
    }
    return 0;
}