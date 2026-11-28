#include <iostream>
#include <cmath>
int main() {
    long long n;
    if (std::cin >> n) {
        n = std::llabs(n);
        int count = 0;
        do {
            count++;
            n /= 10;
        } while (n > 0);
        std::cout << count << std::endl;
    }
    return 0;
}