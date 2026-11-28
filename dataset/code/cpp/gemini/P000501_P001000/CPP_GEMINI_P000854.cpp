#include <iostream>

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << countSetBits(n) << "\n";
    }
    return 0;
}