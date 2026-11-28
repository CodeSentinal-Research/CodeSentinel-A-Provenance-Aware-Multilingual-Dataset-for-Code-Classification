#include <iostream>
void print_1_to_n(int n) {
    if (n <= 0) return;
    print_1_to_n(n - 1);
    std::cout << n << " ";
}
int main() {
    int n;
    if (std::cin >> n) {
        print_1_to_n(n);
        std::cout << std::endl;
    }
    return 0;
}