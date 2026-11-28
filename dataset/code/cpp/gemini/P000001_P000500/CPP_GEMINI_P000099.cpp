#include <iostream>

void printFloydTriangle(int rows) {
    int num = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << num++ << (j == i ? "" : " ");
        }
        std::cout << "\n";
    }
}

int main() {
    int rows;
    if (std::cin >> rows) {
        printFloydTriangle(rows);
    }
    return 0;
}