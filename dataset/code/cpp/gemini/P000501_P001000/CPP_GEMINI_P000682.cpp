#include <iostream>
long long fact_rec(int n) {
    if (n <= 1) return 1;
    return n * fact_rec(n - 1);
}
int main() {
    int n;
    if (std::cin >> n) {
        std::cout << fact_rec(n) << std::endl;
    }
    return 0;
}