#include <iostream>

void printPascalTriangle(int n) {
    for (int i = 0; i < n; i++) {
        long long val = 1;
        for (int j = 0; j <= i; j++) {
            std::cout << val << (j == i ? "" : " ");
            val = val * (i - j) / (j + 1);
        }
        std::cout << "\n";
    }
}

int main() {
    int n;
    if (std::cin >> n) {
        printPascalTriangle(n);
    }
    return 0;
}