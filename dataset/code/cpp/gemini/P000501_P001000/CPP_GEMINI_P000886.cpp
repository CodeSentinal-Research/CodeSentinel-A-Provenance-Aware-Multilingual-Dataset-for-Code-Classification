#include <iostream>

bool isHarshad(int n) {
    if (n <= 0) return false;
    int sum = 0, temp = n;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return n % sum == 0;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::cout << (isHarshad(n) ? "YES" : "NO") << "\n";
    }
    return 0;
}