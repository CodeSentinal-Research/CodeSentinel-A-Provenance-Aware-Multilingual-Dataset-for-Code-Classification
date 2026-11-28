#include <iostream>
#include <cmath>

int main() {
    long long n;
    if (std::cin >> n) {
        long long sign = n < 0 ? -1 : 1;
        long long num = std::llabs(n);
        long long rev = 0;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        std::cout << sign * rev << std::endl;
    }
    return 0;
}