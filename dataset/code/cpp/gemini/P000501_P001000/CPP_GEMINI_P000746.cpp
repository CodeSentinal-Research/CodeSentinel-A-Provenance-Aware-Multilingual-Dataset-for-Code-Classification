#include <iostream>
int josephus(int n, int k) {
    if (n == 1) return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}
int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::cout << josephus(n, k) << std::endl;
    }
    return 0;
}