#include <iostream>
#include <vector>
#include <cmath>

int main() {
    long long n;
    if (std::cin >> n) {
        std::vector<int> freq(10, 0);
        n = std::abs(n);
        if (n == 0) {
            freq[0] = 1;
        } else {
            while (n > 0) {
                freq[n % 10]++;
                n /= 10;
            }
        }
        for (int i = 0; i < 10; i++) {
            std::cout << freq[i] << (i == 9 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}