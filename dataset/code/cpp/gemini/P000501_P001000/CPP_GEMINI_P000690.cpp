#include <iostream>
#include <string>
std::string dec_to_bin(long long n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    return dec_to_bin(n / 2) + std::to_string(n % 2);
}
int main() {
    long long n;
    if (std::cin >> n) {
        std::cout << dec_to_bin(n) << std::endl;
    }
    return 0;
}