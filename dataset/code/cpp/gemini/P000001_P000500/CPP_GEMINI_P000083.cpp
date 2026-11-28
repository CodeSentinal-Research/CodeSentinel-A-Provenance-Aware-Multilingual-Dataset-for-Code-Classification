#include <iostream>

int findLargest(int a, int b, int c) {
    if (a >= b) {
        if (a >= c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b >= c) {
            return b;
        } else {
            return c;
        }
    }
}

int main() {
    int a, b, c;
    if (std::cin >> a >> b >> c) {
        std::cout << findLargest(a, b, c) << "\n";
    }
    return 0;
}